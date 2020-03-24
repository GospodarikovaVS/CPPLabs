#include "Distributor.h"
#include "Product.h"

int Distributor::sell(double budget, Product prod) {
	int count = 0;

	return count;
}

double Distributor::getDefBalance() {
	return defBalance;
}

double Distributor::getProfit() {
	double profit = curBalance - defBalance;
	curBalance = defBalance;
	return profit;
}

int Distributor::buyProducts(int number, Product prod) {
	for (Shelf shelf : shelves)
	{
		if(shelf.checkType(prod))
	}
	//order truck, which will deliver products(MayBe in storage with buffer)
	return numReal;
}