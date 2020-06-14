#include "Client.h"

Client::Client(double balance, bool wholeSale) {
	this->balance = balance;
	this->wholeSale = wholeSale;
}
vector<VCSet> Client::buyVC(VendorCode vc, double amount, TradeOrg* trOrg) {
	return trOrg->BuyProducts(vc, amount, &balance, wholeSale);
}

string Client::buyVCAndPrint(VendorCode vc, double amount, TradeOrg* trOrg) {
	string str = "-------\n";
	str += amount + '\n';
	for (VCSet v : trOrg->BuyProducts(vc, amount, &balance, wholeSale))
	{
		str += (string)v.getVC().getCodeSKU() + '\n';
		str += v.getDateAsString() + '\n';
	}
	return str;
}

double Client::getBalance() {
	return balance;
}