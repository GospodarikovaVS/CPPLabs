#include "Node.h"

#ifndef _NODE_CPP_
#define _NODE_CPP_
template <class T>
Node<T>::Node(T value) {
	this->value = value;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	visited = false;
}

template <class T>
Node<T>::Node(Node<T>* pr, T value) {
	this->value = value;
	left = nullptr;
	right = nullptr;
	parent = pr;
	visited = false;
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
Node<T>* Node<T>::getParent() {
	return this->parent;
}

template <class T>
void Node<T>::setLeftNeigh(Node<T> *l) {
	this->left = l;
}

template <class T>
void Node<T>::setRightNeigh(Node<T> *r) {
	this->right = r;
}

template <class T>
void Node<T>::setParent(Node<T>* pr) {
	this->parent = pr;
}

template <class T>
bool Node<T>::getVisited() { 
	return visited;
}

template <class T>
void Node<T>::setVisited(bool state) {
	visited = state;
}

#endif