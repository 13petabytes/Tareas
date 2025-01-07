#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <cstring>
using namespace std;

template <class T>

class Sorts {

private:

  void cambio(vector<T> &lista,int i, int j){
    
    T aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;  
  };

  void divicionMerge(vector<T> &lista,vector<T> &sublista, int inicio, int fin){
    int mitad;

    if ((fin - inicio) < 1 ){
      return;
    }
    
    mitad = (inicio + fin)/2;
    
    divicionMerge(lista, sublista, inicio, mitad);
    divicionMerge(lista, sublista, mitad + 1, fin);
    ordenarMerge(lista, sublista, inicio, mitad, fin);
    copiaMerge(lista, sublista, inicio, fin);
  }

  void copiaMerge(vector<T> &lista,vector<T> &sublista, int inicio, int fin){
    for (int i = inicio; i <= fin; i++){
      lista[i] = sublista[i];
    }
  };

  void ordenarMerge(vector<T> &lista,vector<T> &sublista, int inicio, int mitad, int fin){
    int i = inicio;
    int j = mitad + 1;
    int k = inicio;

    while (i <= mitad && j <= fin){
      if (lista[i] < lista[j]){
        sublista[k] = lista[i];
        i++;
      } else {
        sublista[k] = lista[j];
        j++;
      }
      k++;
    }
    if (i > mitad){
      for (; j <= fin; j++){
        sublista[k++] = lista[j];
      }
    } else {
      for (; i <= mitad; i++){
        sublista[k++] = lista[i];
      }
    }
  }
    
public:

//ordenadores
vector<T> ordenaSeleccion(vector<T>&lista) {
  
    int X;
  
    for (int i = (lista.size() - 1); i >= 0; i--) {
      
        X = 0;
      
        for (int j = 0; j <= i; j++) {
          
            if (lista[j] > lista[X]) {
              
                X = j;
            }
        }
        if (X != i) {
          
            cambio(lista,i,X); 
        }
    }
  return lista;
}

vector<T> ordenaBurbuja(vector<T>&lista){
  
   for (int i = (lista.size() - 1); i >= 0; i--){
     
     for (int j = 0; j < i; j++){
       
       if (lista[j] > lista[ j + 1 ]){
         
         cambio(lista, j, j + 1);
       }
     }
   }
  return lista;
}

vector<T> ordenaMerge(vector<T>&lista){
  vector <T> sublista(lista.size());

  divicionMerge(lista, sublista, 0, lista.size() - 1);
  
  return lista;
}

//buscadores 

int busqSecuencial(vector<T> &lista, T dato){
  for (int i = 0; i < lista.size(); i++){
    if (lista[i] == dato){
      return i;
    }
  }
  return -1;
}

int busqBinaria(vector<T> &lista, T dato){
  int mitad;
  int inicio = 0;
  int fin = lista.size() - 1;

  while (inicio <= fin){
    mitad = (inicio + fin)/2;
    if (lista[mitad] == dato){
      return mitad;
    } else if (lista[mitad] > dato){
      fin = mitad - 1;
    } else if (lista[mitad] < dato){
      inicio = mitad + 1;
    } 
  }
  if (lista[inicio] != dato){
    return -1;
  }
  return inicio;
}

};