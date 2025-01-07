//Fermín Nieto
//A01707069

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "exception.h"

using namespace std;

template <class T> class BST;

template <class T>
class Node {
private:
  T value;

  Node *left, *right;

  Node<T>* succesor();

public:
  Node(T);
  Node(T, Node<T>*, Node<T>*);
  int nivelMasProfundo1();
  int nivelMasProfundo2(T,int);
  void add(T);
  bool find(T);
  int findAltura(T,int);
  bool findayudaAntecesores(T,std::stringstream&);
  void antecesores(T,std::stringstream&) const;
  void remove(T);
  void removeChilds();
  void inorder(std::stringstream&) const;
  void preorder(std::stringstream&) const;
  void postorder(std::stringstream&) const;
  void levelbylevel(std::stringstream&) const;

  friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
  : value(val), left(le), right(ri) {}

template <class T>
int Node<T>::nivelMasProfundo1(){
  int x = 1;
  x = nivelMasProfundo2(value, x);
  return x;
}

template <class T>
int Node<T>::nivelMasProfundo2(T val, int x){
  if (right != nullptr) {
    x++;
    return right->nivelMasProfundo2(value, x);
  } else if (left != nullptr) {
    x++;
    return left->nivelMasProfundo2(value, x);
  }
  return x;
}

template <class T>
void Node<T>::add(T val) {
  if (val < value) {
    if (left != 0) {
      left->add(val);
    } else {
      left = new Node<T>(val);
    }
  } else {
    if (right != 0) {
      right->add(val);
    } else {
      right = new Node<T>(val);
    }
  }
}

template <class T>
bool Node<T>::find(T val) {
  if (val == value) {
    return true;
  } else if (val > value && right != NULL) {
    return right->find(val);
  } else if (val < value && left != NULL) {
    return left->find(val);
  } 
  return false;
}

template <class T>
int Node<T>::findAltura(T val,int x){
  if (val == value){
    return x;
  } else if(val > value && right != NULL){
    x++;
    return right->findAltura(val,x);
  } else if(val < value && left != NULL){
    x++;
    return left->findAltura(val,x);
  }
  return -1;
}

template <class T>
void Node<T>::antecesores(T val, std::stringstream &aux) const{
    if (val == value) {
      return;
    } else if (val > value && right != NULL) {
      aux << value << " ";
      right->findayudaAntecesores(val, aux);
    } else if (val < value && left != NULL) {
      aux << value << " ";
      left->findayudaAntecesores(val, aux);
    }
}

template <class T>
bool Node<T>::findayudaAntecesores(T val, std::stringstream &aux) {
  if (val == value) {
    return true;
  } else if (val > value && right != NULL) {
    aux << value;
    if (right->value != val){
      aux <<" ";
    } return right->findayudaAntecesores(val,aux);
  } else if (val < value && left != NULL) {
    aux << value;
    if (left->value != val){
      aux <<" ";
    } return left->findayudaAntecesores(val,aux);
  } 
  return false;
}

template <class T>
Node<T>* Node<T>::succesor() {
  Node<T> *le, *ri;

  le = left;
  ri = right;

  if (left == 0) {
    if (right != 0) {
      right = 0;
    }
    return ri;
  }

  if (left->right == 0) {
    left = left->left;
    le->left = 0;
    return le;
  }

  Node<T> *parent, *child;
  parent = left;
  child = left->right;
  while (child->right != 0) {
    parent = child;
    child = child->right;
  }
  parent->right = child->left;
  child->left = 0;
  return child;
}

template <class T>
void Node<T>::remove(T val) {
  Node<T> * succ, *old;

  if (val < value) {
    if (left != 0) {
      if (left->value == val) {
        old = left;
        succ = left->succesor();
        if (succ != 0) {
          succ->left = old->left;
          succ->right = old->right;
        }
        left = succ;
        delete old;
      } else {
        left->remove(val);
      }
    }
  } else if (val > value) {
    if (right != 0) {
      if (right->value == val) {
        old = right;
        succ = right->succesor();
        if (succ != 0) {
          succ->left = old->left;
          succ->right = old->right;
        }
        right = succ;
        delete old;
      } else {
        right->remove(val);
      }
    }
  }
}

template <class T>
void Node<T>::removeChilds() {
  if (left != 0) {
    left->removeChilds();
    delete left;
    left = 0;
  }
  if (right != 0) {
    right->removeChilds();
    delete right;
    right = 0;
  }
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
  if (left != nullptr) {
    left->inorder(aux);
  }
  if (aux.tellp() != 0) {
    aux << " ";
  }
  aux << value;
  if (right != nullptr) {
    right->inorder(aux);
  }
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
  aux << value;
  if (left != 0) {
    aux << " ";
    left->preorder(aux);
  }
  if (right != 0) {
    aux << " ";
    right->preorder(aux);
  }
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const{
  if (left != 0) {
    left->postorder(aux);
  }
  if (right != 0) {
    right->postorder(aux);
  }
  aux << value;
  if (value != 10) {
    aux << " ";
  }
}

template <class T>
void Node<T>::levelbylevel(std::stringstream &aux) const{
  aux << value;
  if (left != 0) {
    aux << " ";
    left->preorder(aux);
  }
  if (right != 0) {
    aux << " ";
    right->preorder(aux);
  }
}

template <class T>
class BST {
private:
  Node<T> *root;
public:
  //costructor y destructor
  BST() : root(0){};
  ~BST(){ 
    removeAll(); 
  };
  //metodos de apollo
  void removeAll(){
    if (root != 0) {
      root->removeChilds();
    } 
    delete root;
    root = 0;
  };

  bool empty() const{
    return (root == 0);
  };

  bool find(T val) const{
    if (root != 0) {
      return root->find(val);
    } else {
      return false;
    }
  }

  //metodos empleados en main

  void add(T val){
    if(root != 0){
      if (!root->find(val)){
        root->add(val);
      }
    } else {
      root = new Node<T>(val);
    }
  };

  string visit() const {
    stringstream aux;
    stringstream aux2;
    aux << "[";
    if (!empty()){
      root->preorder(aux);
      aux << "]\n[";
      root->inorder(aux2);
      aux << aux2.str() <<"]\n[";
      root->postorder(aux);
      aux << "]\n[";
      root->levelbylevel(aux);
      aux<<"]";
    }
    return aux.str();
  }

  T whatlevelamI(T y){
    if (empty()){
      return -1;
    }
    int x = 1;
    return root->findAltura(y,x);
  }

  int height() const{
    int altura = root -> nivelMasProfundo1();
    return altura;      
    }

  string ancestors(T x) const{
    if (empty()){
      return "error";
    }
    
    std::stringstream aux;
    aux << "[";
    if (bool e = find(x) == true){
    root->antecesores(x, aux);
    }
    aux << "]";
    return aux.str();
  }
};
