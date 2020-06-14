#pragma once
#include <vector>
#include "Distributor.h"
#include "VendorCode.h"
using namespace std;

class TradeOrg
{
public:
	TradeOrg(double balance);
	VCSet* orderVCS(VendorCode vc, double amountOrdered, double price);
	void addDistributor(Distributor* distr);
	vector<VCSet> BuyProducts(VendorCode vc, double amountOrdered, double* balance, bool wholeSale);

private:
	double Balance;
	std::vector<Distributor*> distributors;
	void collectProfit();
	
};

