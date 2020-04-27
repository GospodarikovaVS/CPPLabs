#pragma once
#include "VendorCode.h"
#include "TradeOrg.h"
class Client
{
public:
	Client(double balance);
	double buyVC(VendorCode vc, double amount, double balance, TradeOrg trOrg);

private:
	double balance;
	bool wholeSale; //true - розница
};

