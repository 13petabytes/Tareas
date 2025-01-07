//Fermín Nieto A01707069


#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <vector>
#include "exception.h"

using namespace std;

template <class T> class List;

template <class T>

//clase nodo
class Link {
private:
  Link(T);
  Link(T, Link<T>*);
  Link(const Link<T>&);

  T	    value;
  Link<T> *next;

  friend class List<T>;
};

template <class T>
Link<T>::Link(T val){
  value = val;
  next = NULL;
}

template <class T>
Link<T>::Link(T val, Link* nxt){
  value = val;
  next = nxt;
}

template <class T>
Link<T>::Link(const Link<T> &source){
  value = source.value;
  next = source.next;
}

//clase lista
template <class T>
class List {

private:
Link<T> *head;
int 	size;

public:
  List();
  List(const List<T>&) ;
  ~List();

  //metodos de apollo

  void clear(){
    Link<T> *p, *q;

    p = head;
    while (p != 0){
      q = p->next;
      delete p;
      p = q;
    }
    head = 0;
    size = 0;
  };

  void addFirst(T val)  {
    Link<T> *newLink;

    newLink = new Link<T>(val);
    if (newLink == 0) {
      throw OutOfMemory();
    }
    newLink->next = head;
    head = newLink;
    size++;
  };

  bool empty() const{
    return (head == 0);
  };

  /*
  T    getFirst() const{
      if (empty()) {
        throw NoSuchElement();
      }  
      return head->value;
  }
*/
  //metodos que se llamados en main

  std::string toString() const;

  void insertion(T val){
    Link<T> *newLink, *p;

    newLink = new Link<T>(val);
    if (newLink == 0) {
      throw OutOfMemory();
    }

    if (empty()) {
      addFirst(val);
      return;
    }

    p = head;
    while (p->next != 0) {
      p = p->next;
    }

    newLink->next = 0;
    p->next = newLink;
    size++;
  };

  int search(int pedido) const{
    int pos;
    Link<T> *p;
    
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
    Link<T> *p;

    p = head;
    pos = 0;
    
    while (pos != x) {
      p = p->next;
      pos++;
    }

    p->value = y;
  };

  void deleteAt(int x){
    Link<T> *p, *prev;
    int pos = 0;

    if (x == 0) {
        p = head;
        head = head->next;
        delete p;
        size--;
        return;
    }

    p = head;
    prev = nullptr;
    
    while (pos != x && p != nullptr) {
        prev = p;
        p = p->next;
        pos++;
    }

    if (p == nullptr) {
        throw IndexOutOfBounds();
    }

    prev->next = p->next;

    delete p;
    size--;
  };
};

//constructor y destructor

template <class T>
List<T>::List(){
  head = NULL;
  size = 0;
}

template <class T>
List<T>::~List(){
  clear();
  size = 0;
  head = NULL;
}

template <class T>
std::string List<T>::toString() const{
  std::stringstream aux;
  Link<T> *p;

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
}