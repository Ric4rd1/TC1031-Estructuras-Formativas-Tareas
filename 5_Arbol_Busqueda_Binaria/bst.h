/*
 * bst.h
 *
 *  Created on: 05/10/23
 *      Author: ricard
 */

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class BST;

template<class T>
class Node{
    private:
        T value;
	    Node *left, *right;

    public:
        Node(T);
	    Node(T, Node<T>*, Node<T>*);

};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template<class T>
class BST{
    private:
        Node<T> *root;

    public:
        BST();
	    ~BST();
};
#endif /* BST_H_ */