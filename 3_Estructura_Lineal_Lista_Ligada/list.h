#ifndef LIST_H_
#define LIST_H_
/*
 * list.cpp
 *
 *  Created on: 10/08/2020
 *      Author: bvaldesa
 */
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class List;

template <class T>
class Link {
private:
	//Constructores
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}


template <class T>
class List{
    private:
		Link<T> *head;
		int size;

	public:
		//Constructores
		List();
		List(const List<T>&) ;
		~List();

		//Methods
        string toString() const;

		bool empty() const;
		void clear();
		void addFirst(T);
		T getFirst() const;

        void insertion(T val);
		int search(T) const;
		void update(int, T);
		T deleteAt(int);
        
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
	clear();
}


template <class T>
std::string List<T>::toString() const {
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

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
void List<T>::addFirst(T val)  {
	Link<T> *newLink;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		cout<< "Out of Memory"<<endl;
	}
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
T List<T>::getFirst() const {
	if (empty()) {
		cout<< "No such element"<<endl;
	}
	return head->value;
}

template <class T>
void List<T>::insertion(T val){
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		cout<< "Out of Memory"<<endl;
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
}

template <class T>
int List<T>::search(T val) const{
	int pos;
	Link<T> *p;

	p = head;
	pos = 0;

	while (p->value != val) {
		if(p->next == 0){
			return -1;
		}
		p = p->next;
		pos++;
	}

	return pos;
}

template <class T>
void List<T>::update(int index, T val){
	int pos;
	Link<T> *p;

	if (index < 0 || index >= size) {
		cout<<"Index out of Bounds"<<endl;
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}
	p->value = val; 

}

template <class T>
T List<T>::deleteAt(int index){
	int pos;
	T val;
	Link<T> *p, *q;

	if (index < 0 || index >= size) {
		cout<<"Index out of Bounds"<<endl;
	}

	if (index == 0) {
		p = head;

		head = p->next;
		val = p->value;

		delete p;
		size--;

		return val;
	}

	p = head;
	pos = 0;
	while (pos != index) {
		q = p;
		p = p->next;
		pos++;
	}

	val = p->value;
	q->next = p->next;
	delete p;
	size--;

	return val;
	

}
#endif /* LIST_H_ */