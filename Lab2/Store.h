#pragma once
#include "Distributor.h"
#include <vector>
#include "VCSet.h"
#include "Storage.h"

class Store :
	public Distributor
{
public:
	Store(Storage* prStrg);
	void setParentStorage(Storage* prntStrg);
	void orderAllVCSets();
	Storage* getParentStorage();
	double calculateSum(double numReal, VendorCode vc) override;
	vector<VCSet> sell(VendorCode vc, double amount) override;
	void replenishVCS(VendorCode vc, double amount, double price);
	double getProfit() override;
	double getDefBalance() override;
	double getPerExtraCharge();

private:
	const double defBalance = 1000.0;
	const double perExtraCharge = 0.05;
	Storage* parentStorage;
	
};

