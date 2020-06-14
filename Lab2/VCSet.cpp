#include "VCSet.h"
#include "VendorCode.h"
#pragma warning(disable : 4996)

VCSet::VCSet(VendorCode vc, double amount, double price)
{
	this->vc = vc;
	this->amount = amount;
	this->defAmount = amount;
	this -> price = price;
	this->date = time(0);
}
VCSet::VCSet(VendorCode vc, double amount, double price, time_t t)
{
	this->vc = vc;
	this->amount = amount;
	this->defAmount = amount;
	this->price = price;
	this->date = t;
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

char* VCSet::getDateAsString() {
	return ctime(&date);
}
time_t VCSet::getDate() {
	return date;
}
VCSet VCSet::createDaughterVCS(double amount) {
	increaseAmount(-amount);
	return VCSet(vc, amount, price, date);
}