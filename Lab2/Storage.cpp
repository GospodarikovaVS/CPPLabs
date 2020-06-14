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
vector<VCSet> Storage::sell(VendorCode vc, double amount) { 
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

VCSet* Storage::deliverVCSToStore(VendorCode vc, double amountOrdered, double price) {
	int i = 0;
	for (VCSet* vcs : vcSets)
	{
		if (vcs->checkType(vc))
		{
			if (amountOrdered <= vcs->getCurAmount())
			{
				vcs->increaseAmount(-amountOrdered);
				orderVCS(vc, amountOrdered, price);
				VCSet* vcsOrd = new VCSet(vc, amountOrdered, price, vcs->getDate());
				return vcsOrd;
			}
			else {
				//vcs->increaseAmount(-vcs->getCurAmount());
				vcSets.erase(vcSets.begin()+i);
				orderVCS(vc, vcs->getDefAmount(), price);
				VCSet* vcsOrd = new VCSet(vc, amountOrdered, price, vcs->getDate());
				return vcsOrd;
			}
		}
		i++;
	}
	return nullptr;
}
void Storage::orderVCS(VendorCode vc, double amountOrdered, double price) {//rewrite
	VCSet* vcs = prntTrOrg->orderVCS(vc, amountOrdered, price);
	vcSets.push_back(vcs);
}
void Storage::orderAllVCSets() {
	vector<VendorCode> vecVC;
	bool checker = true;
	for (int i = vcSets.size()-1; i >= 0; i--) {
		for(VendorCode vc : vecVC)
		{
			if (vc.getCodeSKU() == vcSets[i]->getVC().getCodeSKU())
				checker = false;
		}
		if (checker) {
			vecVC.push_back(vcSets[i]->getVC());
			if (vcSets[i]->getCurAmount() < vcSets[i]->getDefAmount()) {
				vcSets.push_back(prntTrOrg->orderVCS(
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