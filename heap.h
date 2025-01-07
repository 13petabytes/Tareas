//Fermín Nieto
//A01707069

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

template <class T>
class Heap {

private:
    T *data;
    unsigned int sizev;
    unsigned int count;
    unsigned int parent(unsigned int pos) const{
        return (pos - 1) / 2;
    };

public:
//constructor y destructor

    Heap(unsigned int sze){
        sizev = sze;
	    data = new T[sizev];
	    if (data == 0) {
		    throw OutOfMemory();
    	}
	    count = 0;
        };
	~Heap(){
        delete [] data;
    	data = 0;
	    sizev = 0;
	    count = 0;
    };
//metodos
    std::string toString() const{
        std::stringstream aux;
	    aux << "[";	for (unsigned int i = 0; i < count; i++) {
		    if (i != 0) {
			aux << " ";
		    } aux << data[i];
	    } aux << "]";
	    return aux.str();
    };
    
    unsigned int left(unsigned int pos) const{
        return ((2 * pos) + 1);
    };
    
	unsigned int right(unsigned int pos) const{
        return ((2 * pos) + 2);
    };

    void swap(unsigned int i, unsigned int j){
        T aux = data[i];
	    data[i] = data[j];
	    data[j] = aux;
    };

    bool full() const{
        return (count == sizev);
    };

    void push(T val){
        unsigned int pos;
        if (full()) {
		    throw Overflow();
	    }

	    pos = count;
	    count++;
	    while (pos > 0 && val < data[parent(pos)]) {
		    data[pos] = data[parent(pos)];
		    pos = parent(pos);
	    }
	    data[pos] = val;
    };

    bool empty() const{
        return (count == 0);
    };

    void heapify(unsigned int pos){
        unsigned int le = left(pos);
	    unsigned int ri = right(pos);
	    unsigned int min = pos;
	    if (le <= count && data[le] < data[min]) {
		    min = le;
	    }
	    if (ri <= count && data[ri] < data[min]) {
		    min = ri;
	    }
    	if (min != pos) {
	    	swap(pos, min);
	    	heapify(min);
	    }
    };
    
    T pop(){
        if (empty()) {
		    throw NoSuchElement();
	    }
	    T aux = data[0];

	    data[0] = data[--count];
	    heapify(0);
	    return aux;
    };

    unsigned int size(){
        unsigned int pos;
	    return (pos = count);
    };

    T top(){
        return data[0];
    }

};