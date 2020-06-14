#pragma once
#include <vector>
#include "VCSet.h"
using namespace std;

class Distributor
{
public:
	double orderProducts(double number, VendorCode vc);
	void addVCSet(VCSet* vcs);
	bool checkAvailabilityVC(VendorCode vc);
	void addVCSet(VendorCode vc, double amount, double price);
	virtual double calculateSum(double numReal, VendorCode vc);
	virtual double getProfit();
	virtual vector<VCSet> sell(VendorCode vc, double amount);
	virtual double getDefBalance();

	//void changeCurBalance(double changing);
	//double getCurBalance();

protected:
	double curBalance;
	vector<VCSet*> vcSets;
	float perMinAcceptLvl;
};

