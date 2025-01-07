#ifndef QUADRATIC_H_
#define QUADRATIC_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class Key, class Value>
class Quadratic {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	Quadratic(unsigned int, Key, unsigned int (*f) (const Key));
	~Quadratic();
	bool full() const;
	bool put(Key, Value);
	bool contains(const Key) const;
	Value get(const Key);
	void clear();
	std::string toString() const;
};

template <class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int sze, Key init, unsigned int (*f) (const Key)) {
	size = sze;
	keys = new Key[size];
	if (keys == 0) {
		throw OutOfMemory();
	}
	initialValue = init;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = init;
	}
	values = new Value[size];
	if (values == 0) {
		throw OutOfMemory();
	}
	for (unsigned int i = 0; i < sze; i++) {
		values[i] = 0;
	}

	func = f;
	count = 0;
}

template <class Key, class Value>
Quadratic<Key, Value>::~Quadratic() {
	delete[] keys;
	keys = 0;
	delete[] values;
	values = 0;
	size = 0;
	func = 0;
	count = 0;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::full() const {
	return (count >= size);
}

template <class Key, class Value>
long Quadratic<Key, Value>::indexOf(const Key k) const {
	unsigned int start = func(k) % size;
	unsigned int i = start;
	unsigned int j = 0;

	do {
		if (keys[i] == k) {
			return i;
		}
		j++;
		i = (start + j * j) % size;
	} while (keys[i] != initialValue && j < size);

	return -1;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::put(Key k, Value v) {
	if (full()) {
		throw Overflow();
	}

	unsigned int start = func(k) % size;
	unsigned int i = start;
	unsigned int j = 0;

	while (j < size) {
		if (keys[i] == initialValue || keys[i] == k) {
			keys[i] = k;
			values[i] = v;
			if (keys[i] == initialValue) {
				count++;
			}
			return true;
		}
		j++;
		i = (start + j * j) % size;
	}

	return false;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::contains(const Key k) const {
	return (indexOf(k) != -1);
}

template <class Key, class Value>
Value Quadratic<Key, Value>::get(const Key k) {
	long pos = indexOf(k);
	if (pos != -1) {
		return values[pos];
	}
	throw NoSuchElement();
}

template <class Key, class Value>
void Quadratic<Key, Value>::clear() {
	count = 0;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = initialValue;
		values[i] = 0;
	}
}

template <class Key, class Value>
std::string Quadratic<Key, Value>::toString() const {
	std::stringstream aux;
	for (unsigned int i = 0; i < size; i++) {
		if (keys[i] != initialValue) {
			aux << "(" << i << " " << keys[i] << " : " << values[i] << ") ";
		}
	}
	return aux.str();
}

#endif /* QUADRATIC_H_ */
