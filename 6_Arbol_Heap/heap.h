/*
 * heap.h
 *
 *  Created on: 15/11/23
 *      Author: ricard
 */

#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <cstdio>
using namespace std;

class Exception : public exception {
protected:
	string text;

public:
	Exception() throw(): text("Basic exception"){};
	~Exception() throw(){};
	virtual const char* what() const throw(){return text.c_str();};
};	


class OutOfMemory : public Exception {
public:
	OutOfMemory() throw(){
		text = string("OutOfMemory");};
};


class NoSuchElement : public Exception {
public:
	NoSuchElement() throw(){
		text = string("NoSuchElement");};
};


class Overflow : public Exception {
public:
	Overflow() throw(){
		text = string("Overflow");};
};


template <class T>
class Heap {
    private:
        T *data;
        unsigned int sze;
        unsigned int cant;

        unsigned int parent(unsigned int pos) const;
        unsigned int left(unsigned int pos) const;
        unsigned int right(unsigned int pos) const;
        void heapify(unsigned int);
        void swap(unsigned int first, unsigned int next);

    public:
        
        Heap(unsigned int);
        ~Heap();
        bool empty() const;
        bool full() const;
        void push(T);
        void pop();
        void clear();
        T top();
        int size() {return cant-1;};
        string toString() const;
};

template <class T>
Heap<T>::Heap(unsigned int ze)  {
	data = new T[ze];
	if (data == 0) {
		throw OutOfMemory();
	}
	sze = ze+1;
	cant = 1;
}

template <class T>
Heap<T>::~Heap() {
    delete [] data;
    data = 0;
    sze = 0;
    cant = 0;
}

template <class T>
bool Heap<T>::empty() const {
    return(cant == 1);
}

template <class T>
bool Heap<T>::full() const {
	return (cant == sze);
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
    return int(pos/2);
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
    return pos*2;
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
    return (2*pos)+1;
}

template <class T>
void Heap<T>::swap(unsigned int first, unsigned int next) {
    T aux = data[first];
    data[first] = data[next];
    data[next] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri= right(pos);
	unsigned int min = pos;
	if (le <= cant && data[le]< data[min]){
		min=le;
	}
	if (ri <= cant && data[ri]< data[min]){
		min=ri;
	}
	if (min!=pos){
		swap(pos,min);
		heapify(min);
	}
	
}

template <class T>
void Heap<T>::push(T val)  {
	unsigned int pos;
	if (full()) {
		throw Overflow();
	}
	pos = cant;
	cant++;
	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;

}

template <class T>
void Heap<T>::pop()  {
	if (empty()) {
		throw NoSuchElement();
	}
	T aux;
	aux = data[1];
	data[1]= data[--cant];
	heapify(1);
}

template <class T>
T Heap<T>::top()  {
	if (!empty()) {
		return data[1];
	}
	return 0;
	
}

template <class T>
void Heap<T>::clear() {
	cant = 1;
}

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (unsigned int i = 1; i < cant; i++) {
		if (i != 1) {
			aux << " ";
		}
		aux << data[i];
	}
	aux << "]";
	return aux.str();
}

#endif
