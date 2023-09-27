#ifndef DLIST_H_
#define DLIST_H_
/*
 * dlist.h
 *
 *  Created on: 27/09/2023
 *      Author: ricard
 */
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class DList;

template <class T>
class DLink{
    private:
        //Constructores
        DLink(T);
        DLink(T, DLink<T>*, DLink<T>*);
        DLink(const DLink<T>&);

        //Atributos
        T         value;
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
class DList{
    public:
        //Constructores
        DList();
	    DList(const DList<T>&);
	    ~DList();

        //Metodos
        string toStringForward() const;
        string toStringBackward() const;
        bool empty() const;
        void clear();
        void addFirst(T val);
        T deleteFirst();

        void insertion(T);
        int search(T) const;
        void update(int, T);
        T deleteAt(int);

    private:
        //Atributos
    	DLink<T> *head;
	    DLink<T> *tail;
	    int       size;
};

template <class T>
DList<T>::DList(): head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
DList<T>::DList(const DList<T> &source)  {
	DLink<T> *p, *q;

	if (source.empty()) {
		size = 0;
		head = 0;
		tail = 0;
	} else {
		p = source.head;
		head = new DLink<T>(p->value);
		if (head == 0) {
			cout<< "Out of Memory"<<endl;
            return;
		}
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new DLink<T>(p->value, q, 0);
			if (q->next == 0) {
				cout<< "Out of Memory"<<endl;
                return;
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

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
void DList<T>::addFirst(T val)  {
	DLink<T> *newLink;

	newLink = new DLink<T>(val);
	if (newLink == 0) {
		cout<< "Out of Memory"<<endl;
        return;
	}
	newLink->next = head;
    newLink->previous = tail;
	head = newLink;
    tail = newLink;
	size++;
}

template <class T>
T DList<T>::deleteFirst() {
    T val;
    DLink<T> *p;

    if (empty()) {
        cout<< "No such element"<<endl;
    }

    p = head;
    p->value = val;

    head = p->next;
    head->previous = 0;
    delete p;
    size--;
    return val;
}

template <class T>
std::string DList<T>::toStringBackward() const {
	std::stringstream aux;
	DLink<T> *p;

	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string DList<T>::toStringForward() const {
    std::stringstream aux;
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
}

template <class T>
void DList<T>::insertion(T val){
    DLink<T> *newLink, *p;

	newLink = new DLink<T>(val);
	if (newLink == 0) {
		cout<< "Out of Memory"<<endl;
        return;
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
    newLink->previous = p;
	p->next = newLink;
    tail = newLink;
	size++;
}

template <class T>
int DList<T>::search(T val) const{
    int pos = 0;
    DLink<T> *p;

    p = head;
    while (p != 0) {
        if (p->value == val) {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

template <class T>
void DList<T>::update(int index, T val){
    int pos;
    DLink<T> *p;

    if (index < 0 || index >= size) {
        cout<<"Index out of Bounds"<<endl;
        return;
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
T DList<T>::deleteAt(int index){
    int pos;
    T val;
    DLink<T> *p, *q;

    if (index < 0 || index >= size) {
        cout<<"Index out of Bounds"<<endl;
        return -1;
    }

    if (index == 0) {
        return deleteFirst();
    }

    p = head;
    pos = 0;
    while (pos != index) {
        p = p->next;
        pos++;
    }

    val = p->value;
    q = p->previous;
    q->next = p->next;
    if (p->next != 0) {
        p->next->previous = q;
    }
    size--;
    delete p;
    return val;
}

#endif /* DLIST_H_ */