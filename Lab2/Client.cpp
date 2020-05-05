#include "Client.h"

Client::Client(double balance, bool wholeSale) {
	this->balance = balance;
	this->wholeSale = wholeSale;
}
double Client::buyVC(VendorCode vc, double amount, double balance, TradeOrg trOrg) {
	return trOrg.BuyProducts(vc, amount, &balance, wholeSale);
}