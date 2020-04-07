#include "Distributor.h"
#include "VendorCode.h"

int Distributor::sell(double budget, VendorCode vc) {
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

int Distributor::buyProducts(int number, VendorCode vc) {
	int numReal = 0;
	for (Shelf shelf : shelves)
	{
		if (shelf.checkType(vc));
	}
	//order truck, which will deliver products(MayBe in storage with buffer)
	return numReal;
}