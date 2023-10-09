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
        //Constructors
        Node(T);
	    Node(T, Node<T>*, Node<T>*);
        //Methods
        void add(T);
        bool find(T);

        void inorder(std::stringstream&) const;
	    void preorder(std::stringstream&) const;

};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

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
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
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

template<class T>
class BST{
    private:
        Node<T> *root;

    public:
        //Constructor
        BST();
        //Destructor
	    ~BST();
        //Methods
        bool empty() const;
        void add(T);
        bool find(T) const;
       
        std::string inorder() const;
	    std::string preorder() const;
        string visit() const;
        int height() const;
        string ancestors(T) const;
        int whatlevelamI(T) const;


};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}

template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template<class T>
string BST<T>::visit() const{
    std::stringstream aux;

    aux << preorder();
    aux << "\n";
    aux << inorder();

    return aux
}

template <class T>
int BST<T>::height() const{

    return 0;
}

template <class T>
string BST<T>::ancestors(T) const{
    
    return 0;
}

template <class T>
int BST<T>::whatlevelamI(T) const{

    return 0;
}
#endif /* BST_H_ */