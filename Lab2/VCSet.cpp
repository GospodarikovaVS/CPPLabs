#include "VCSet.h"
#include "VendorCode.h"

VCSet::VCSet(VendorCode vc, int amount, double price)
{
	this->vc = vc;
	this->amount = amount;
	this->defAmount = amount;
	this -> price = price;
}
int VCSet::buyAmount(int amount)
{
	return 1;
}
VendorCode VCSet::getVC()
{
	return this->vc;
}
void VCSet::setPrice(double price)
{
	this->price = price;
}
double VCSet::getPrice()
{
	return price;
}
int VCSet::getCurAmount()
{
	return amount;
}
int VCSet::getDefAmount()
{
	return defAmount;
}
void VCSet::increaseAmount(int increasment)
{
	this->amount += increasment;
}

bool VCSet::checkType(VendorCode vc)
{
	return vc.getCodeSKU == this->vc.getCodeSKU;
}