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

	//inputing
	void addBalancedNode(T n);
	void addBalancedNode(Node<T>* n);
	////completly in right/left
	void addNodeToRight(T n);
	void addNodeToRight(Node<T>* n);
	void addNodeToLeft(T n);
	void addNodeToLeft(Node<T>* n);
	////customizable adding
	void addNodeWithManaging(T n);
	void addNodeWithManaging(Node<T>* n);

private:
	Node<T>* root;
	void clearBinaryTree(Node<T>* n);
	string showNodeAsString(Node<T>* n);
	vector<T> showNodeAsVector(Node<T>* n);
	Node<T>* searchForNearestEmptyNode(Node<T>* curNode, int curDeep, int* minDeep, Node<T>** resNode);
};
#include"BinaryTree.cpp"

#endif