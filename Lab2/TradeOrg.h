#pragma once
#include <vector>
#include "Distributor.h"
#include "Product.h"

class TradeOrg
{
public:
	int orderProducts(int reqNumber, Product prod);
	void addDistributor(Distributor distr);

private:
	double Balance;
	std::vector<Distributor> distributors;
	void collectProfit();
	int BuyProducts(int number, Product prod);
	
};

