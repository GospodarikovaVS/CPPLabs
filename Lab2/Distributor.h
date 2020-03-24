#pragma once
#include <vector>
#include "Shelf.h"

class Distributor
{
public:
	int buyProducts(int number, Product prod);
	double getProfit();
	double getDefBalance();
	int sell(double balance, Product prod);

protected:
	std::vector<Shelf> shelves; //map with counting
	double defBalance;
	double curBalance;
	float perMinAcceptLvl;
};

