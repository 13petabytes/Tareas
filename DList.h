//Fermín Nieto A01707069


#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <vector>
#include "exception.h"

using namespace std;

template <class T> class DList;

template <class T>
class DLink {
private:
  DLink(T);
  DLink(T, DLink<T>*, DLink<T>*);
  DLink(const DLink<T>&);

  T	    value;
  DLink<T> *previous;
  DLink<T> *next;

  friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {

private:
  DLink<T> *head;
  DLink<T> *tail;
  int 	 size;

public:

  DList();
  DList(const DList<T>&);
  ~DList();

  //metodos de apollo

  void clear(){
    DLink<T> *p, *q;

    p = head;
    while (p != 0) {
      q = p->next;
      delete p;
      p = q;
    }
    head = 0;
    tail = 0;
    size = 0;
  };

  bool empty() const{
      if(head == NULL && tail == NULL && size == 0) {
        return true;
      }
      return false;
  }

  
  //metodos empleados en main

  string toStringForward() const {
    stringstream aux;
    DLink<T> *p;

    p = head;
    aux << "[";
    while (p != 0) {
      aux << p->value;
      if (p->next != 0) {
        aux << ", ";
      }
      p = p->next;
    }
    aux << "]";
    return aux.str();
  };

  string toStringBackward() const {
    stringstream aux;
    DLink<T> *p;
    
    p = tail;
    aux << "[";
    while (p != 0) {
      aux << p->value;
      
      if (p->previous != 0){
        aux << ", ";
      }
      p = p->previous;
    }
    aux << "]";
    return aux.str();
  };
  
  void insertion(T val) {
    DLink<T> * nuevo_nodo = new DLink<T>(val);
    if (nuevo_nodo == NULL) {
      throw OutOfMemory();
    }

    if (empty()) {
      head = nuevo_nodo;
      tail = nuevo_nodo;
    } else {
      nuevo_nodo->previous = tail;
      tail->next = nuevo_nodo;
      tail = nuevo_nodo;
    }
    size++;
  };

  int search(T pedido) const{
    int pos;
    DLink<T> *p;

    p = head;
    pos = 0;
    while (p != nullptr) {
      if (p->value == pedido){
        return pos;
      }

      p = p->next;
      pos++;
    }
    return -1;
  };

  void update(int x, int y){
    int pos;
    DLink<T> *p;

    p = head;
    pos = 0;

    while (pos != x) {
      p = p->next;
      pos++;
    }

    p->value = y;
  };

  void deleteAt(int x){
    DLink<T> *p;
    p = head;

    if (x == 0) {
        head = head->next;
        head->previous = NULL;
        delete p;
        size--;
        return;
    }

    for (int i = 0; i < x; i++) {
      p = p->next;
    }
    
    p->previous->next = p->next;

    p->next->previous = p->previous;
    
    delete p;
    size--;
  };

};

template <class T>
DList<T>::DList() {
  head = NULL;
  tail = NULL;
  size = 0;
}

template <class T>
DList<T>::~DList() {
  clear();
}
