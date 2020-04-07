#pragma once
#include <vector>
#include "Distributor.h"
#include "VendorCode.h"

class TradeOrg
{
public:
	int orderProducts(int reqNumber, VendorCode vc);
	void addDistributor(Distributor distr);

private:
	double Balance;
	std::vector<Distributor> distributors;
	void collectProfit();
	int BuyProducts(int number, VendorCode vc);
	
};

