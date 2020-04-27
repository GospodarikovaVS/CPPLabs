#include "VCSet.h"
#include "VendorCode.h"

VCSet::VCSet(VendorCode vc, double amount, double price)
{
	this->vc = vc;
	this->amount = amount;
	this->defAmount = amount;
	this -> price = price;
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
double VCSet::getCurAmount()
{
	return amount;
}
double VCSet::getDefAmount()
{
	return defAmount;
}
void VCSet::increaseAmount(double increasment)
{
	this->amount += increasment;
}

bool VCSet::checkType(VendorCode vc)
{
	return vc.getCodeSKU() == this->vc.getCodeSKU();
}