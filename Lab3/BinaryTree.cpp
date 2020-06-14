#include "BinaryTree.h"

#ifndef _BIN_TREE_CPP_
#define _BIN_TREE_CPP_

//implementing and deleting
template <class T>
BinaryTree<T>::BinaryTree(Node<T>* r) {
	this->root = r;
	curNode = root;
}
template <class T>
BinaryTree<T>::BinaryTree(T r) {
	this->root = new Node<T>(r);
	curNode = root;
}
template <class T>
BinaryTree<T>::~BinaryTree() {
	curNode = nullptr;
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
////searching
template <class T>
Node<T>* BinaryTree<T>::SearchNodeByValue(T val) {
	return searchingByValue(root, val);
}
template <class T>
Node<T>* BinaryTree<T>::searchingByValue(Node<T>* n, T val) {
	if (n->getValue() == val) {
		return n;
	}
	else {
		if (n->getRightNeigh()) {
			Node<T>* rn = searchingByValue(n->getRightNeigh(), val);
			if (rn) return rn;
		}
		if (n->getLeftNeigh()) {
			Node<T>* ln = searchingByValue(n->getLeftNeigh(), val);
			if (ln) return ln;
		}
	}
	return nullptr;
}
template <class T>
Node<T>* BinaryTree<T>::SearchNodeWithMinValue() {
	return searchingMinNode(root, root);
}
template <class T>
Node<T>* BinaryTree<T>::searchingMinNode(Node<T>* n, Node<T>* minNode) {
	Node<T>* minVal = minNode;
	if (n->getValue() < minVal->getValue()) {
		minVal = n;
	}
	if (n->getRightNeigh()) {
		Node<T>* rn = searchingMinNode(n->getRightNeigh(), minVal);
		if (rn && rn->getValue() < minVal->getValue())
			minVal = rn;
	}
	if (n->getLeftNeigh()) {
		Node<T>* ln = searchingMinNode(n->getLeftNeigh(), minVal);
		if (ln && ln->getValue() < minVal->getValue())
			minVal = ln;
	}
	return minVal;
}
template <class T>
Node<T>* BinaryTree<T>::SearchNodeWithMaxValue() {
	return searchingMaxNode(root, root);
}
template <class T>
Node<T>* BinaryTree<T>::searchingMaxNode(Node<T>* n, Node<T>* maxNode) {
	Node<T>* maxVal = maxNode;
	if (n->getValue() > maxVal->getValue()) {
		maxVal = n;
	}
	if (n->getRightNeigh()) {
		Node<T>* rn = searchingMaxNode(n->getRightNeigh(), maxVal);
		if (rn && rn->getValue() > maxVal->getValue())
			maxVal = rn;
	}
	if (n->getLeftNeigh()) {
		Node<T>* ln = searchingMaxNode(n->getLeftNeigh(), maxVal);
		if (ln && ln->getValue() > maxVal->getValue())
			maxVal = ln;
	}
	return maxVal;
}
template <class T>
T BinaryTree<T>::SearchMinValue() {
	return searchingMinValue(root, root->getValue());
}
template <class T>
T BinaryTree<T>::searchingMinValue(Node<T>* n, T min) {
	T minVal = min;
	if (n->getValue() < minVal) {
		minVal = n->getValue();
	}
	if (n->getRightNeigh()) {
		T rn = searchingMinValue(n->getRightNeigh(), minVal);
		if (rn < minVal)
			minVal = rn;
	}
	if (n->getLeftNeigh()) {
		T ln = searchingMinValue(n->getLeftNeigh(), minVal);
		if (ln < minVal)
			minVal = ln;
	}
	return minVal;
}
template <class T>
T BinaryTree<T>::SearchMaxValue() {
	return searchingMaxValue(root, root->getValue());
}
template <class T>
T BinaryTree<T>::searchingMaxValue(Node<T>* n, T max) {
	T maxVal = max;
	if (n->getValue() > maxVal) {
		maxVal = n->getValue();
	}
	if (n->getRightNeigh()) {
		T rn = searchingMaxValue(n->getRightNeigh(), maxVal);
		if (rn > maxVal)
			maxVal = rn;
	}
	if (n->getLeftNeigh()) {
		T ln = searchingMaxValue(n->getLeftNeigh(), maxVal);
		if (ln > maxVal)
			maxVal = ln;
	}
	return maxVal;
}

//inputing
template <class T>
void BinaryTree<T>::addBalancedNode(T n) {
	int minDeep = 0;
	Node<T>* rNode = searchForNearestEmptyNode(root, 0, &minDeep, &root);
	Node<T>* newNode = new Node<T>(rNode, n);
	if (!rNode->getLeftNeigh()) {
		rNode->setLeftNeigh(newNode);
	} else rNode->setRightNeigh(newNode);
}
template <class T>
void BinaryTree<T>::addBalancedNode(Node<T>* n) {
	int minDeep = 0;
	Node<T>* rNode = searchForNearestEmptyNode(root, 0, &minDeep, &root);
	n->setParent(rNode);
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
	curNode->setRightNeigh(new Node<T>(curNode, n));
}
template <class T>
void BinaryTree<T>::addNodeToRight(Node<T>* n) {
	Node<T>* curNode = root;
	while (curNode->getRightNeigh()) {
		curNode = curNode->getRightNeigh();
	}
	n->setParent(curNode);
	curNode->setRightNeigh(n);
}
template <class T>
void BinaryTree<T>::addNodeToLeft(T n) {
	Node<T>* curNode = root;
	while (curNode->getLeftNeigh()) {
		curNode = curNode->getLeftNeigh();
	}
	curNode->setLeftNeigh(new Node<T>(curNode, n));
}
template <class T>
void BinaryTree<T>::addNodeToLeft(Node<T>* n) {
	Node<T>* curNode = root;
	while (curNode->getLeftNeigh()) {
		curNode = curNode->getLeftNeigh();
	}
	n->setParent(curNode);
	curNode->setLeftNeigh(n);
}

//iterator
template <class T>
void BinaryTree<T>::start() {
	if (curNode->getVisited()) {
		restartIterations(root);
	}
	curNode = root;
	operator+();
}

template <class T>
void BinaryTree<T>::restartIterations(Node<T>* curNode) {
	curNode->setVisited(false);
	if (curNode->getLeftNeigh())
	{
		restartIterations(curNode->getLeftNeigh());
	}
	if (curNode->getRightNeigh()) 
	{
		restartIterations(curNode->getRightNeigh());
	}
}
////ops
template <class T>
void BinaryTree<T>::operator+() {
	/*curNode = nullptr;*/
	if (curNode->getLeftNeigh() 
		&& !curNode->getLeftNeigh()->getVisited()) {
		curNode = curNode->getLeftNeigh();
		operator+();
	}
	else if (!curNode->getVisited()) {
		curNode->setVisited(true);
	}
	else if (curNode->getRightNeigh() 
		&& !curNode->getRightNeigh()->getVisited()) {
		curNode = curNode->getRightNeigh(); 
		operator+();
	}
	else {
		curNode = curNode->getParent();
		if (curNode) {
			operator+();
		}
		
	}
}
template <class T>
void BinaryTree<T>::operator-() {
	if(curNode->getRightNeigh()
		&& curNode->getRightNeigh()->getVisited()) {
		curNode = curNode->getRightNeigh();
		operator-();
	}
	else if (curNode->getVisited()) {
		curNode->setVisited(false);
		curNode = curNode->getLeftNeigh();
	}
	else if (curNode->getLeftNeigh()
		&& curNode->getLeftNeigh()->getVisited()) {
		curNode = curNode->getLeftNeigh();
		operator-();
	}
	else {
		curNode = curNode->getParent();
		operator-();
	}
}
template <class T>
Node<T>* BinaryTree<T>::operator->() {
	return curNode;
}

#endif
