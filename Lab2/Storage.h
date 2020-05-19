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
	void sell(VendorCode vc, double amount) override;
	double getDefBalance() override;
	double getPerExtraCharge();
	double deliverVCSToStore(VendorCode vc, double amountOrdered);
	void orderVCS(VendorCode vc, double amountOrdered);


private:
	const double defBalance = 10000.0;
	const double perExtraCharge = 0.025;
	TradeOrg* prntTrOrg;

};

