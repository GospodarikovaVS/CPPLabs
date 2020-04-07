#pragma once
#include <vector>
#include "VCSet.h"

class Distributor
{
public:
	int buyProducts(int number, VendorCode vc);
	double getProfit();
	double getDefBalance();
	int sell(double balance, VendorCode vc);

protected:
	std::vector<VCSet> vcSets; 
	double defBalance;
	double curBalance;
	float perMinAcceptLvl;
};

