#include "TradeOrg.h"
#include <vector>
#include "Distributor.h"
#include "Store.h"
#include "Storage.h"


double TradeOrg::orderVCS(VendorCode vc, double amountOrdered) {

	return 0.0;
}

void TradeOrg::addDistributor(Distributor distr) {
	distributors.push_back(distr);
	Balance -= distr.getDefBalance();
}

double TradeOrg::BuyProducts(VendorCode vc, double amountOrdered, double balance, bool wholeSale) {
	double numReal = amountOrdered;
	//search of distr
	for (Distributor dist : distributors)
	{
		//if(wholeSale && decltype(dist) == Store)
	}
	//order
	//price
	
	return numReal;
}

void TradeOrg::collectProfit() {
	for (Distributor distr : distributors)
	{
		Balance += distr.getProfit();
	}
}