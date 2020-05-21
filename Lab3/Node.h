//#pragma once

#ifndef _NODE_H_
#define _NODE_H_

template <class T> 
class Node
{
public:
	Node(T value);
	~Node();
	void setValue(T value);
	T getValue();
	Node<T>* getLeftNeigh();
	Node<T>* getRightNeigh();
	void setLeftNeigh(Node<T> *l);
	void setRightNeigh(Node<T> *r);
private:
	T value;
	Node<T>* left;
	Node<T>* right;
};
#include "Node.cpp"
#endif

