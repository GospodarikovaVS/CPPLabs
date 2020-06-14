#pragma once
#include "Node.h"
#include <vector>
#include <string>
using namespace std;

#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_
template <class T>
class BinaryTree
{
public:
	//implementing and deleting
	BinaryTree(Node<T>* r);
	BinaryTree(T r);
	~BinaryTree();

	//interactions with root
	void setRoot(Node<T>* r);
	Node<T>* getRoot();
	void setRootValue(T r);
	T getRootValue();

	//outputing
	string showAsString();
	vector<T> showAsVector();
	////searching
	Node<T>* SearchNodeByValue(T val);
	Node<T>* SearchNodeWithMinValue();
	Node<T>* SearchNodeWithMaxValue();
	T SearchMinValue();
	T SearchMaxValue();

	//inputing
	void addBalancedNode(T n);
	void addBalancedNode(Node<T>* n);
	////completly in right/left
	void addNodeToRight(T n);
	void addNodeToRight(Node<T>* n);
	void addNodeToLeft(T n);
	void addNodeToLeft(Node<T>* n);

	//iterator
	void start();
	////ops
	Node<T>* operator->();
	void operator+();
	void operator-();


private:
	Node<T>* curNode;
	Node<T>* root;
	void restartIterations(Node<T>* curNode);
	void clearBinaryTree(Node<T>* n);
	string showNodeAsString(Node<T>* n);
	vector<T> showNodeAsVector(Node<T>* n);
	T searchingMinValue(Node<T>* n, T minVal);
	T searchingMaxValue(Node<T>* n, T maxVal);
	Node<T>* searchingByValue(Node<T>* n, T val);
	Node<T>* searchingMinNode(Node<T>* n, Node<T>* minNode);
	Node<T>* searchingMaxNode(Node<T>* n, Node<T>* maxNode);
	Node<T>* searchForNearestEmptyNode(Node<T>* curNode, int curDeep, int* minDeep, Node<T>** resNode);
};
#include"BinaryTree.cpp"

#endif