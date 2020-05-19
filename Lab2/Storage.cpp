#include "Storage.h"
#include <vector>

Storage::Storage(TradeOrg* trOrg) {
	this->curBalance = this->defBalance;
	vcSets = std::vector<VCSet*>();
	prntTrOrg = trOrg;
}
double Storage::calculateSum(double numReal, VendorCode vc) {
	double price = 0;
	for (VCSet* vcs : vcSets)
	{
		if (vcs->checkType(vc))
			price = vcs->getPrice();
	}
	return numReal * (price*perExtraCharge);
}
double Storage::getDefBalance() {
	return defBalance;
}
double Storage::getPerExtraCharge() {
	return perExtraCharge;
}

double Storage::getProfit() {
	double profit = curBalance - defBalance;
	curBalance = defBalance;
	return profit;
}
void Storage::sell(VendorCode vc, double amount) {
	for (VCSet* vcs : vcSets)
	{
		if (vcs->checkType(vc))
		{
			vcs->increaseAmount(-amount);
			if(vcs->getCurAmount()<vcs->getDefAmount())
				orderVCS(vc, amount);
			return;
		}
	}
}

double Storage::deliverVCSToStore(VendorCode vc, double amountOrdered) {
	for (VCSet* vcs : vcSets)
	{
		if (vcs->checkType(vc))
		{
			if (amountOrdered <= vcs->getCurAmount())
			{
				vcs->increaseAmount(-amountOrdered);
				orderVCS(vc, amountOrdered);
				return amountOrdered;
			}
			else {
				vcs->increaseAmount(-vcs->getCurAmount());
				orderVCS(vc, vcs->getDefAmount());
				return vcs->getCurAmount();
			}
		}
	}
}
void Storage::orderVCS(VendorCode vc, double amountOrdered) {
	for (VCSet* vcs : vcSets)
	{
		if (vcs->checkType(vc))
		{
			vcs->increaseAmount(prntTrOrg->
				orderVCS(vc, amountOrdered, vcs->getPrice()));
			return;
		}
	}
}