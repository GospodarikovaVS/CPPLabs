#include "Client.h"

Client::Client(double balance) {
	this->balance = balance;
}
double Client::buyVC(VendorCode vc, double amount, double balance, TradeOrg trOrg) {
	return trOrg.BuyProducts(vc, amount, balance, wholeSale);
}