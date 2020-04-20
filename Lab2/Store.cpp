#include "Store.h"

Store::Store(Storage* prStrg) {
	this -> curBalance = this -> defBalance;
	parentStorage = prStrg;
}

void Store::sell(VendorCode vc, int amount) {
	for (VCSet vcs : vcSets)
	{
		if (vcs.checkType(vc))
			vcs.increaseAmount(-amount);
		replenishVCS(&vcs);
	}
}
Storage* Store::getParentStorage() {
	return parentStorage;
}

void Store::replenishVCS(VCSet* vcs) {
	int amount = parentStorage->
		deliverVCSToStore(vcs->getVC,
			vcs->getDefAmount - vcs->getCurAmount);
	vcs->increaseAmount(amount);
}

double Store::getDefBalance() {
	return defBalance;
}
double Store::getPerExtraCharge() {
	return perExtraCharge;
}
void Store::setParentStorage(Storage* prntStrg) {
	parentStorage = prntStrg;
}
double Store::calculateSum(int numReal, VendorCode vc) {
	double price = 0;
	for (VCSet vcs : vcSets)
	{
		if (vcs.checkType(vc))
			price = vcs.getPrice();
	}
	return numReal * (price * perExtraCharge);
}
double Store::getProfit() {
	double profit = curBalance - defBalance;
	curBalance = defBalance;
	return profit;
}