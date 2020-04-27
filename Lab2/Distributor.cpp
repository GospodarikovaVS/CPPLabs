#include "Distributor.h"
#include "VendorCode.h"

double Distributor::orderProducts(double number, VendorCode vc) {
	double numReal = 0;
	for (VCSet vcs : vcSets)
	{
		if (vcs.checkType(vc))
			numReal = (vcs.getCurAmount()>=number) ? number : vcs.getCurAmount();
	}
	return numReal;
}
double Distributor::getDefBalance() {
	return 0.0;
}
void Distributor::addVCSet(VCSet vcs) {
	vcSets.push_back(vcs);
}
void Distributor::addVCSet(VendorCode vc, double amount, double price) {
	vcSets.push_back(VCSet(vc, amount, price));
}
double Distributor::calculateSum(double numReal, VendorCode vc) {
	return 0.0;
}
double Distributor::getProfit() {
	return 0.0;
}
void Distributor::sell(VendorCode vc, double amount) {
}