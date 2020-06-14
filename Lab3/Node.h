//#pragma once

#ifndef _NODE_H_
#define _NODE_H_

template <class T> 
class Node
{
public:
	Node(T value);
	Node(Node<T>* pr, T value);
	~Node();
	void setValue(T value);
	T getValue();
	Node<T>* getLeftNeigh();
	Node<T>* getRightNeigh();
	Node<T>* getParent();
	void setLeftNeigh(Node<T> *l);
	void setRightNeigh(Node<T> *r);
	void setParent(Node<T>* pr);
	bool getVisited();
	void setVisited(bool state);
private:
	T value;
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
	bool visited;
};
#include "Node.cpp"
#endif

