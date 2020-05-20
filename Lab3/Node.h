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
	template <typename L>
	Node<L>* getLeftNeigh();
	template <typename R>
	Node<R>* getRightNeigh();
	template <typename L>
	void setLeftNeigh(Node<L> *l);
	template <typename R>
	void setRightNeigh(Node<R> *r);
private:
	T value;
	Node* left;
	Node* right;
};
#include "Node.cpp"
#endif

