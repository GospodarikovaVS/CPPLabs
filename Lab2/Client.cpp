#include "Client.h"

Client::Client(double balance, bool wholeSale) {
	this->balance = balance;
	this->wholeSale = wholeSale;
}
double Client::buyVC(VendorCode vc, double amount, TradeOrg* trOrg) {
	return trOrg->BuyProducts(vc, amount, &balance, wholeSale);
}

double Client::getBalance() {
	return balance;
}