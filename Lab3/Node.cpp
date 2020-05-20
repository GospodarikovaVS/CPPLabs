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
template <typename L>
Node<L>* Node<T>::getLeftNeigh() {
	return this->left;
}

template <class T>
template <typename R>
Node<R>* Node<T>::getRightNeigh() {
	return this->right;
}

template <class T>
template <typename L>
void Node<T>::setLeftNeigh(Node<L> *l) {
	this->left = l;
}

template <class T>
template <typename R>
void Node<T>::setRightNeigh(Node<R> *r) {
	this->right = r;
}

#endif