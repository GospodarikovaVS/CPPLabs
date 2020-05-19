#pragma once
#include "Node.h"

#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_
template <class T>
class BinaryTree
{
public:
	BinaryTree(Node<T>* r);
	BinaryTree(T r);
	void setRoot(Node<T>* r);
	Node<T>* getRoot();
	void setRootValue(T r);
	T getRootValue();

private:
	Node<T>* root;
};
#include"BinaryTree.cpp"

#endif