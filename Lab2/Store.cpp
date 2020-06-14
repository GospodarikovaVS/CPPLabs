#include "Store.h"

Store::Store(Storage* prStrg) {
	this -> curBalance = this -> defBalance;
	parentStorage = prStrg;
	vcSets = std::vector<VCSet*>();
}

vector<VCSet> Store::sell(VendorCode vc, double amount) {
	int amountOrdered = amount;
	vector<VCSet> vecVCSets;
	int i = 0;
	for (VCSet* vcs : vcSets)
	{
		if (vcs->checkType(vc))
		{
			if (vcs->getCurAmount() >= amountOrdered)
			{
				vecVCSets.push_back(vcs->createDaughterVCS(amount));
				orderAllVCSets();
				return vecVCSets;
			}
			else {
				amountOrdered -= vcs->getCurAmount();
				vecVCSets.push_back(vcs->createDaughterVCS(vcs->getCurAmount()));
			}
		}
		i++;
	}
	orderAllVCSets();
	return vecVCSets;
}
Storage* Store::getParentStorage() {
	return parentStorage;
}

void Store::orderAllVCSets() {
	vector<VendorCode> vecVC;
	bool checker = true;
	for (int i = vcSets.size() - 1; i >= 0; i--) {
		for (VendorCode vc : vecVC)
		{
			if (vc.getCodeSKU() == vcSets[i]->getVC().getCodeSKU())
				checker = false;
		}
		if (checker) {
			vecVC.push_back(vcSets[i]->getVC());
			if (vcSets[i]->getCurAmount() < vcSets[i]->getDefAmount()) {
				vcSets.push_back(parentStorage->deliverVCSToStore(
					vcSets[i]->getVC(),
					vcSets[i]->getDefAmount(),
					vcSets[i]->getPrice()));
			}
		}
		if (vcSets[i]->getCurAmount() == 0) {
			vcSets.erase(vcSets.begin() + i);
		}
		checker = true;
	}

}

void Store::replenishVCS(VendorCode vc, double amount, double price) {
	VCSet* vcs = parentStorage->
		deliverVCSToStore(vc, amount, price);
	vcSets.push_back(vcs);
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
double Store::calculateSum(double numReal, VendorCode vc) {
	double price = 0;
	for (VCSet* vcs : vcSets)
	{
		if (vcs->checkType(vc))
			price = vcs->getPrice();
	}
	return numReal * (price * perExtraCharge);
}
double Store::getProfit() {
	double profit = curBalance - defBalance;
	curBalance = defBalance;
	return profit;
}