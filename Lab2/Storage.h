#pragma once
#include "Distributor.h"
#include "Store.h"

class Storage :
	public Distributor
{
public:
	Storage(std::vector<Store*> strs);
	void addSubsidaryStore(Store* store);
	double calculateSum(int numReal, VendorCode vc) override;
	double getProfit() override;
	void sell(VendorCode vc, int amount) override;
	double getDefBalance();
	double getPerExtraCharge();
	int deliverVCSToStore(VendorCode vc, int amountOrdered);


private:
	const double defBalance = 10000.0;
	const double perExtraCharge = 0.025;
	std::vector<Store*> subsidiaryStores;

};

