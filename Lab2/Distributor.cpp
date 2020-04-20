#include "Distributor.h"
#include "VendorCode.h"




int Distributor::orderProducts(int number, VendorCode vc) {
	int numReal = 0;
	for (VCSet vcs : vcSets)
	{
		if (vcs.checkType(vc))
			numReal = (vcs.getCurAmount()>=number) ? number : vcs.getCurAmount();
	}
	return numReal;
}
void Distributor::addVCSet(VCSet vcs) {
	vcSets.push_back(vcs);
}
void Distributor::addVCSet(VendorCode vc, int amount, double price) {
	vcSets.push_back(VCSet(vc, amount, price));
}