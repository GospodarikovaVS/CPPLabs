#include "Storage.h"
#include <vector>

Storage::Storage(std::vector<Store*> strs) {
	this->curBalance = this->defBalance;
	subsidiaryStores = strs;
}
double Storage::calculateSum(int numReal, VendorCode vc) {
	double price = 0;
	for (VCSet vcs : vcSets)
	{
		if (vcs.checkType(vc))
			price = vcs.getPrice();
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
void Storage::sell(VendorCode vc, int amount) {
	for (VCSet vcs : vcSets)
	{
		if (vcs.checkType(vc))
			vcs.increaseAmount(-amount);
	}
	//order truck, which will deliver products(MayBe in storage with buffer)
}
void Storage::addSubsidaryStore(Store* store) {
	subsidiaryStores.push_back(store);
}

int Storage::deliverVCSToStore(VendorCode vc, int amountOrdered) {
	for (VCSet vcs : vcSets)
	{
		if (vcs.checkType(vc))
		{
			if (amountOrdered <= vcs.getCurAmount)
			{
				vcs.increaseAmount(-amountOrdered);
				return amountOrdered;
			}
			else {
				vcs.increaseAmount(-vcs.getCurAmount);
				return vcs.getCurAmount;
			}
		}
	}
}