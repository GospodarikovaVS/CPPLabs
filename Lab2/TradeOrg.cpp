#include "TradeOrg.h"
#include <vector>
#include "Distributor.h"

TradeOrg::TradeOrg() {
}

int TradeOrg::orderProducts(int reqNumber, Product prod) {
return BuyProducts(reqNumber, prod);
}

void TradeOrg::addDistributor(Distributor distr) {
	distributors.push_back(distr);
	Balance -= distr.getDefBalance();
}

int TradeOrg::BuyProducts(int number, Product prod) {
	int numReal = number;
	if (Balance >= prod.buyShares(numReal))
		Balance -= prod.buyShares(numReal);
	else {
		collectProfit();
		if (Balance >= prod.buyShares(numReal))
			Balance -= prod.buyShares(numReal);
		else {
			numReal = (int)Balance / (int)prod.getPrice();
			Balance -= prod.buyShares(numReal);
		}
	}
	//order truck, which will deliver products(MayBe in storage with buffer)
	return numReal;
}

void TradeOrg::collectProfit() {
	for (Distributor distr : distributors)
	{
		Balance += distr.getProfit();
	}
}