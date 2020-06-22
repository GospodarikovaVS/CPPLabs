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
	class Iterator {
		Node<T>* curNode;
	public:
		Iterator(Node<T>* n) 
		{ 
			curNode = n;
		} //начиная с бегин
		Node<T>& operator*() {
			return *curNode;
		}
		Node<T>& operator++() {
			/*curNode = nullptr;*/
			if (curNode) {
				if (curNode->getLeftNeigh()
					&& !curNode->getLeftNeigh()->getVisited()) {
					curNode = curNode->getLeftNeigh();
					operator++();
				}
				else if (!curNode->getVisited()) {
					curNode->setVisited(true);
					return *curNode;
				}
				else if (curNode->getRightNeigh()
					&& !curNode->getRightNeigh()->getVisited()) {
					curNode = curNode->getRightNeigh();
					operator++();
				}
				else {
					curNode = curNode->getParent();
					if (curNode) {
						operator++();
					}

				}
			}
		}
		Node<T>& operator--() {
			if (curNode) {
				if (curNode->getRightNeigh()
					&& curNode->getRightNeigh()->getVisited()) {
					curNode = curNode->getRightNeigh();
					operator--();
				}
				else if (curNode->getVisited()) {
					curNode->setVisited(false);
					curNode = curNode->getLeftNeigh();
					return *curNode;
				}
				else if (curNode->getLeftNeigh()
					&& curNode->getLeftNeigh()->getVisited()) {
					curNode = curNode->getLeftNeigh();
					operator--();
				}
				else {
					curNode = curNode->getParent();
					operator--();
				}
			}
		}
		Node<T>& operator++(int) {
			/*curNode = nullptr;*/
			if (curNode) {
				if (curNode->getLeftNeigh()
					&& !curNode->getLeftNeigh()->getVisited()) {
					curNode = curNode->getLeftNeigh();
					operator++();
				}
				else if (!curNode->getVisited()) {
					curNode->setVisited(true);
					return *curNode;
				}
				else if (curNode->getRightNeigh()
					&& !curNode->getRightNeigh()->getVisited()) {
					curNode = curNode->getRightNeigh();
					operator++();
				}
				else {
					curNode = curNode->getParent();
					if (curNode) {
						operator++();
					}

				}
			}
		}
		Node<T>& operator--(int) {
			if (curNode) {
				if (curNode->getRightNeigh()
					&& curNode->getRightNeigh()->getVisited()) {
					curNode = curNode->getRightNeigh();
					operator--();
				}
				else if (curNode->getVisited()) {
					curNode->setVisited(false);
					curNode = curNode->getLeftNeigh();
					return *curNode;
				}
				else if (curNode->getLeftNeigh()
					&& curNode->getLeftNeigh()->getVisited()) {
					curNode = curNode->getLeftNeigh();
					operator--();
				}
				else {
					curNode = curNode->getParent();
					operator--();
				}
			}
		}
		Node<T>& restart() {
			while (curNode->getParent())
			{
				curNode = curNode->getParent();
			}
			restartIterations(curNode);
			operator++;
		}
		~Iterator() {
			if (curNode) {
				while (curNode->getParent())
				{
					curNode = curNode->getParent();
				}
				restartIterations(curNode);
			}
		}
		void restartIterations(Node<T>* curNode) {
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
		bool operator!= (const Iterator& it) { return curNode != it.curNode; }
		bool operator== (const Iterator& it) { return curNode == it.curNode; }
	};
	Iterator begin() { return findMostLeft(root); }
	Iterator end() { return root->getParent(); }


private:
	Node<T>* root;
	void clearBinaryTree(Node<T>* n);
	//iterator
	Node<T>* findMostLeft(Node<T>* n);
	//outputing
	string showNodeAsString(Node<T>* n);
	vector<T> showNodeAsVector(Node<T>* n);
	////searching
	T searchingMinValue(Node<T>* n, T minVal);
	T searchingMaxValue(Node<T>* n, T maxVal);
	Node<T>* searchingByValue(Node<T>* n, T val);
	Node<T>* searchingMinNode(Node<T>* n, Node<T>* minNode);
	Node<T>* searchingMaxNode(Node<T>* n, Node<T>* maxNode);
	Node<T>* searchForNearestEmptyNode(Node<T>* curNode, int curDeep, int* minDeep, Node<T>** resNode);
};
#include"BinaryTree.cpp"

#endif