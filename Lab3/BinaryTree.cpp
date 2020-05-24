#include "BinaryTree.h"

#ifndef _BIN_TREE_CPP_
#define _BIN_TREE_CPP_

//implementing and deleting
template <class T>
BinaryTree<T>::BinaryTree(Node<T>* r) {
	this->root = r;
}
template <class T>
BinaryTree<T>::BinaryTree(T r) {
	this->root = new Node<T>(r);
}
template <class T>
BinaryTree<T>::~BinaryTree() {
	clearBinaryTree(root);
}
template <class T>
void BinaryTree<T>::clearBinaryTree(Node<T> *n) {
	if (n->getLeftNeigh()) {
		clearBinaryTree(n->getLeftNeigh());
		n->setLeftNeigh(nullptr);
	}
	if (n->getRightNeigh()) {
		clearBinaryTree(n->getRightNeigh());
		n->setRightNeigh(nullptr);
	}
	delete n;
}


//interactions with root
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


//outputing
template <class T>
string BinaryTree<T>::showAsString() {
	return showNodeAsString(root) + "\n";
}
template <class T>
string BinaryTree<T>::showNodeAsString(Node<T> *n) {
	string str = "";
	if (n->getLeftNeigh() != nullptr)
		str += showNodeAsString(n->getLeftNeigh());
	try {
	str += n->getValue() + "  ";
	}
	catch (...) {
		return "Error";
	}
	if (n->getRightNeigh())
		str += showNodeAsString(n->getRightNeigh());
	return str;
}
template <class T>
vector<T> BinaryTree<T>::showAsVector() {
	return showNodeAsVector(root);
}
template <class T>
vector<T> BinaryTree<T>::showNodeAsVector(Node<T> *n) {
	vector<T> vec = vector<T>();
	if (n->getLeftNeigh())
	{
		vector<T> v = showNodeAsVector(n->getLeftNeigh());
		for (int i = 0; i < v.size(); i++) {
			vec.push_back(v[i]);
		}
	}
	vec.push_back(n->getValue());
	if (n->getRightNeigh()) 
	{
		vector<T> v = showNodeAsVector(n->getRightNeigh());
		for (int i = 0; i < v.size(); i++) {
			vec.push_back(v[i]);
		}
	}
	return vec;
}


//inputing
template <class T>
void BinaryTree<T>::addBalancedNode(T n) {
	Node<T>* newNode = new Node<T>(n);
	int minDeep = 0;
	Node<T>* rNode = searchForNearestEmptyNode(root, 0, &minDeep, &root);
	if (!rNode->getLeftNeigh()) {
		rNode->setLeftNeigh(newNode);
	} else rNode->setRightNeigh(newNode);
}
template <class T>
void BinaryTree<T>::addBalancedNode(Node<T>* n) {
	int minDeep = 0;
	Node<T>* rNode = searchForNearestEmptyNode(root, 0, &minDeep, &root);
	if (!rNode->getLeftNeigh()) {
		rNode->setLeftNeigh(n);
	}
	else rNode->setRightNeigh(n);
}
template <class T>
Node<T>* BinaryTree<T>::searchForNearestEmptyNode(Node<T>* curNode, int curDeep, int* minDeep, Node<T>** resNode) {
	Node<T>* rNode = *resNode;
	if (curNode->getLeftNeigh() && curNode->getRightNeigh()) {
		rNode = searchForNearestEmptyNode(curNode->getLeftNeigh(), curDeep + 1, minDeep, &rNode);
		rNode = searchForNearestEmptyNode(curNode->getRightNeigh(), curDeep + 1, minDeep, &rNode);
	}
	else {
		if ((*minDeep > (curDeep + 1)) || (*minDeep == 0)) {
			*minDeep = curDeep + 1;
			rNode = curNode;
		}
	}
	return rNode;
}
////completly in right/left
template <class T>
void BinaryTree<T>::addNodeToRight(T n) {
	Node<T>* curNode = root;
	while (curNode->getRightNeigh()) {
		curNode = curNode->getRightNeigh();
	}
	curNode->setRightNeigh(new Node<T>(n));
}
template <class T>
void BinaryTree<T>::addNodeToRight(Node<T>* n) {
	Node<T>* curNode = root;
	while (curNode->getRightNeigh()) {
		curNode = curNode->getRightNeigh();
	}
	curNode->setRightNeigh(n);
}
template <class T>
void BinaryTree<T>::addNodeToLeft(T n) {
	Node<T>* curNode = root;
	while (curNode->getLeftNeigh()) {
		curNode = curNode->getLeftNeigh();
	}
	curNode->setLeftNeigh(new Node<T>(n));
}
template <class T>
void BinaryTree<T>::addNodeToLeft(Node<T>* n) {
	Node<T>* curNode = root;
	while (curNode->getLeftNeigh()) {
		curNode = curNode->getLeftNeigh();
	}
	curNode->setLeftNeigh(n);
}
////customizable adding
template <class T>
void BinaryTree<T>::addNodeWithManaging(T n) {
}
template <class T>
void BinaryTree<T>::addNodeWithManaging(Node<T>* n) {
}

#endif
