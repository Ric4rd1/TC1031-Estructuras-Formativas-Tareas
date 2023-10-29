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

        Node<T>* succesor();

    public:
        //Constructors
        Node(T);
	    Node(T, Node<T>*, Node<T>*);
        //Methods
        void add(T);
        bool find(T);
        void remove(T);
        void removeChilds();
		int height() const;
		bool ancestors(stringstream &, T);
		int whatlevelamI(T data);

        void inorder(std::stringstream&) const;
	    void preorder(std::stringstream&) const;
		void postorder(std::stringstream&) const;
		void levelorder(std::stringstream&) const;

        friend class BST<T>;

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
int Node<T>::height() const {
	int l = 0, r = 0;
	if (left != 0) {
		l = left -> height();
	}
	if (right != 0) {
		r = right -> height();
	}
	if (l == 0 && r == 0) {
		return 1;
	}
	if (l > r) {
		return l + 1;
	}
	else {
		return r + 1;
	}
}

template <class T>
bool Node<T>::ancestors(stringstream &aux, T data) {
	if (data < value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (left -> ancestors(aux, data) && left != 0);
	}
	else if (data == value) {
		return true;
	}
	else if (data > value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (right -> ancestors(aux, data) && right != 0);
	}
	return false;
}

template <class T>
int Node<T>::whatlevelamI(T data) {
	if (data < value) {
		if (left != 0) {
			return left -> whatlevelamI(data) + 1;
		}
	}
	else if (data == value) {
		return 1;
	}
	else if (data > value) {
		if (right != 0) {
			return right -> whatlevelamI(data) + 1;
		}
	}
	return -1;
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

template <class T>
void Node<T>::postorder(std::stringstream &aux) const {
	if (left != 0) {
		left->postorder(aux);
		aux << " ";
	}
	if (right != 0) {
		right->postorder(aux);
		aux << " ";
	}
	aux << value;
}

template <class T>
void Node<T>::levelorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left -> levelorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right -> levelorder(aux);
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
        void removeAll();
       
        std::string inorder() const;
	    std::string preorder() const;
		std::string postorder() const;
		std::string levelorder() const;
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
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
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

template <class T>
std::string BST<T>::postorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::levelorder() const {
    stringstream aux;
    aux << "[";
    if (!empty()) {
        root -> levelorder(aux);
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
	aux << "\n";
	aux << postorder();
	aux << "\n";
	aux << levelorder();

    return aux.str();
}

template <class T>
int BST<T>::height() const {
	int h = root -> height();
	return h;
}

template <class T>
string BST<T>::ancestors(T data) const{
    stringstream aux;
	aux << "[";
	if (root -> find(data)) {
		root -> ancestors(aux, data);		
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T data) const{
	int nivel;
	if (root) {
		nivel = root -> whatlevelamI(data);
	}
	if (nivel < 0) { return -1;}
	else { return nivel;}
}
#endif /* BST_H_ */