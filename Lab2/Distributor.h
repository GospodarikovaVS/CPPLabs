#pragma once
#include <vector>
#include "VCSet.h"

class Distributor
{
public:
	int orderProducts(int number, VendorCode vc);
	void addVCSet(VCSet vcs);
	void addVCSet(VendorCode vc, int amount, double price);
	virtual double calculateSum(int numReal, VendorCode vc) = 0;
	virtual double getProfit() = 0;
	virtual void sell(VendorCode vc, int amount) = 0;

	//void changeCurBalance(double changing);
	//double getCurBalance();

protected:
	double curBalance;
	std::vector<VCSet> vcSets;
	float perMinAcceptLvl;
};

