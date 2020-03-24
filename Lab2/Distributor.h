#pragma once
class Distributor
{
public:
	virtual double getProfit() = 0;
	virtual int sell() = 0;

private:
	const double defBudget;
	const float perMinAcceptLvl;

};

