#include <iostream>
#include <stdio.h>
using namespace std;

class Funciones {
public:

  long sumaIterativa(int n) {
    long x = 0;
    for (int i = 1; i <= n; i++) {
      x += i;
    }
    return x;
  }

  long sumaRecursiva(int n) {
    if (n == 0) {
      return 0;
    } 
    else{
      return n + sumaRecursiva(n-1);
    }
  }

  long sumaDirecta(int n) {
    return (n*(n+1))/2;
  }
};
