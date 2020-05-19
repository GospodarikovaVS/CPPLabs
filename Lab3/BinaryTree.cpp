#include "BinaryTree.h"

#ifndef _BIN_TREE_CPP_
#define _BIN_TREE_CPP_
template <class T>
BinaryTree<T>::BinaryTree(Node<T>* r) {
	this->root = r;
}
template <class T>
BinaryTree<T>::BinaryTree(T r) {
	this->root = &Node<T>(r);
}
template <class T>
void BinaryTree<T>::setRoot(Node<T>* r) {
	this->root = r;
}
template <class T>
Node<T>* BinaryTree<T>::getRoot() {
	return this->root;
}
template <class T>
void BinaryTree<T>::setRootValue(T rv) {
	this->root->setValue(rv);
}
template <class T>
T BinaryTree<T>::getRootValue() {
	return this->root->getValue();
}


#endif