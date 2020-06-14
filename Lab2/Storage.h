#pragma once
#include "Distributor.h"
#include "TradeOrg.h"

class Storage :
	public Distributor
{
public:
	Storage(TradeOrg* trOrg);
	double calculateSum(double numReal, VendorCode vc) override;
	double getProfit() override;
	vector<VCSet> sell(VendorCode vc, double amount) override;
	double getDefBalance() override;
	double getPerExtraCharge();
	VCSet* deliverVCSToStore(VendorCode vc, double amountOrdered, double price);
	void orderAllVCSets();


private:
	void orderVCS(VendorCode vc, double amountOrdered, double price);
	const double defBalance = 10000.0;
	const double perExtraCharge = 0.025;
	TradeOrg* prntTrOrg;

};

