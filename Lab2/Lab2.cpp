// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Client.h"
#include "TradeOrg.h"
#include "Store.h"

#include <iostream>

using namespace std;

int main()
{
	VendorCode vc = VendorCode("Молоко", 0.9, 1, true, false);
	VCSet vcsStrg = VCSet(vc, 50, 43);
	VCSet vcsStr = VCSet(vc, 10, 43, vcsStrg.getDate());
	cout << vcsStrg.getDateAsString();
	cout << vcsStr.getDateAsString();
	TradeOrg trOrg = TradeOrg(1000000);
	Storage strg = Storage(&trOrg);
	Store str = Store(&strg);
	strg.addVCSet(&vcsStrg);
	str.addVCSet(&vcsStr);
	trOrg.addDistributor(&str);
	trOrg.addDistributor(&strg);
	for (int i = 0; i < 1000; i++) {
	Client WholeSaleClient = Client(10000, true);
	std::cout << (WholeSaleClient.getBalance()) << "\n";
	std::cout << (WholeSaleClient.buyVCAndPrint(vc, 11, &trOrg)) << "\n";
	std::cout << (WholeSaleClient.getBalance()) << "\n";
	
	}
	/*
	Client notWholeSaleClient = Client(10000, false) ;
	trOrg.addDistributor(&strg);
	trOrg.addDistributor(&str);
	VCSet vcStrg = VCSet(vc, 50, 100);
	VCSet vcStr = VCSet(vc, 5, 100);
	strg.addVCSet(&vcStrg);
	str.addVCSet(&vcStr);
	strg.orderVCS(vc, 50);
	str.replenishVCS(&vcStr, 5);


	std::cout << (vcStr.getCurAmount()) << "\n";
	std::cout << (vcStrg.getCurAmount()) << "\n";
	std::cout << (notWholeSaleClient.getBalance()) << "\n";
	std::cout << (notWholeSaleClient.buyVC(vc, 80, &trOrg)) << "\n";
	std::cout << (vcStr.getCurAmount()) << "\n";
	std::cout << (vcStrg.getCurAmount()) << "\n";
	std::cout << (notWholeSaleClient.getBalance()) << "\n";*/

    std::cout << "Hello World!\n";
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
