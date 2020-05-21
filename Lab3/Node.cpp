#include "Node.h"

#ifndef _NODE_CPP_
#define _NODE_CPP_
template <class T>
Node<T>::Node(T value) {
	this->value = value;
	left = nullptr;
	right = nullptr;
}

template <class T>
Node<T>::~Node() {
	delete left;
	delete right;
}

template <class T>
void Node<T>::setValue(T value) {
	this->value = value;
}

template <class T>
T Node<T>::getValue() {
	return value;
}

template <class T>
Node<T>* Node<T>::getLeftNeigh() {
	return this->left;
}

template <class T>
Node<T>* Node<T>::getRightNeigh() {
	return this->right;
}

template <class T>
void Node<T>::setLeftNeigh(Node<T> *l) {
	this->left = l;
}

template <class T>
void Node<T>::setRightNeigh(Node<T> *r) {
	this->right = r;
}

#endif