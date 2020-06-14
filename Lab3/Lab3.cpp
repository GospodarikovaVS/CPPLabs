// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
#include<vector>
using namespace std;

int main()
{
	BinaryTree<int> bt = BinaryTree<int>(1);
	bt.setRootValue(4);
	bt.addNodeToLeft(3);
	bt.addNodeToRight(7);
	vector<int> vec = bt.showAsVector();
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	cout << endl;
	BinaryTree<string> bts = BinaryTree<string>("root");
	bts.addNodeToLeft("left");
	bts.addNodeToRight("right");
	bts.addBalancedNode("ll");
	bts.addBalancedNode("lr");
	bts.addBalancedNode("rl");
	bts.addBalancedNode("rr");
	Node<string>* n = new Node<string>("lll");
	bts.addBalancedNode(n);
	vector<string> vecs = bts.showAsVector();
	for (int i = 0; i < vecs.size(); i++) {
		cout << vecs[i];
		cout << endl;
	}
	cout << endl;
	cout << endl;
	bts.start();
	cout << bts.operator->()->getValue();
	bts.operator+();
	cout << endl;
	cout << bts.operator->()->getValue();
	bts.operator-();
	cout << endl;
	cout << bts.operator->()->getValue();
	cout << endl;
	cout << endl;
	bts.start();
	while(bts.operator->()) {
		cout << bts.operator->()->getValue();
		bts.operator+();
		cout << endl;
	}
	cout << endl;
	cout << bts.showAsString();


	Node<string>* n2 = bts.SearchNodeByValue("lll");
	cout << n2->getValue();
	cout << endl;
	Node<string>* nMin = bts.SearchNodeWithMinValue();
	cout << nMin->getValue();
	cout << endl;
	string max = bts.SearchMaxValue();
	cout << max;
	cout << endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
