#pragma once
#include <vector>
#include "Distributor.h"
#include "Product.h"

class TradeOrg
{
public:
	int orderProducts(int reqNumber, Product prod) {
		return BuyProducts(reqNumber, prod);
	}
	void addDistributor(Distributor distr) {
		distributors.push_back(distr);
		Budget -= distr.
	}
	//double reqInvestment(double investment) { //there is nothing usefull
	//	if (Budget > investment) {
	//		Budget -= investment;
	//		return investment;
	//	}
	//}

private:
	double Budget;
	std::vector<Distributor> distributors;

	void collectProfit() {
		for(Distributor distr : distributors)
		{
			//Budget += distr.getProfit();
		}
	}
	int BuyProducts(int number, Product prod) {
		int numReal = number;
		if (Budget >= numReal * prod.price)
			Budget -= numReal * prod.price;
		else {
			collectProfit();
			if (Budget >= numReal * prod.price)
				Budget -= numReal * prod.price;
			else {
				numReal = (int)Budget / (int)prod.price;
				Budget -= numReal * prod.price;
			}
		}
		//order truck, which will deliver products(MayBe in storage with buffer)
		return numReal;
	}
	
};

