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
	Storage* getParentStorage();
	double calculateSum(int numReal, VendorCode vc) override;
	void sell(VendorCode vc, int amount) override;
	void replenishVCS(VCSet* vcs);
	double getProfit() override;
	double getDefBalance();
	double getPerExtraCharge();

private:
	const double defBalance = 1000.0;
	const double perExtraCharge = 0.05;
	Storage* parentStorage;
	
};

