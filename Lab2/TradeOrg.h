#pragma once
#include <vector>
#include "Distributor.h"
#include "VendorCode.h"

class TradeOrg
{
public:
	TradeOrg(double balance);
	double orderVCS(VendorCode vc, double amountOrdered, double price);
	void addDistributor(Distributor* distr);
	double BuyProducts(VendorCode vc, double amountOrdered, double* balance, bool wholeSale);

private:
	double Balance;
	std::vector<Distributor*> distributors;
	void collectProfit();
	
};

