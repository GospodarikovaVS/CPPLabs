#pragma once
#include "VendorCode.h"
#include "TradeOrg.h"
class Client
{
public:
	Client(double balance, bool wholeSale);
	vector<VCSet> buyVC(VendorCode vc, double amount, TradeOrg *trOrg);
	string buyVCAndPrint(VendorCode vc, double amount, TradeOrg* trOrg);
	double getBalance();

private:
	double balance;
	bool wholeSale; //true - розница
};

