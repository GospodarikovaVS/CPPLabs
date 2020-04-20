#include "TradeOrg.h"
#include <vector>
#include "Distributor.h"

//TradeOrg::TradeOrg() {
//}

int TradeOrg::orderProducts(int reqNumber, VendorCode vc) {
return BuyProducts(reqNumber, vc);
}

void TradeOrg::addDistributor(Distributor distr) {
	distributors.push_back(distr);
	Balance -= distr.getDefBalance();
}

int TradeOrg::BuyProducts(int number, VendorCode vc) {
	int numReal = number;
	/*if (Balance >= vc.buyShares(numReal))
		Balance -= vc.buyShares(numReal);
	else {
		collectProfit();
		if (Balance >= vc.buyShares(numReal))
			Balance -= vc.buyShares(numReal);
		else {
			numReal = (int)Balance / (int)vc.getPrice();
			Balance -= vc.buyShares(numReal);
		}
	}*/
	//order truck, which will deliver products(MayBe in storage with buffer)
	return numReal;
}

void TradeOrg::collectProfit() {
	for (Distributor distr : distributors)
	{
		Balance += distr.getProfit();
	}
}