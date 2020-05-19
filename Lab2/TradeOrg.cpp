#include "TradeOrg.h"
#include <vector>
#include "Distributor.h"
#include "Store.h"
#include "Storage.h"
#include "Supplier.h"

TradeOrg::TradeOrg(double balance) {
	Balance = balance;
}

double TradeOrg::orderVCS(VendorCode vc, double amountOrdered, double price) {
	Supplier sup = Supplier();
	VCSet order = sup.supplyVCSet(vc, amountOrdered, price);
	Balance -= price * order.getCurAmount();
	return order.getCurAmount();
}

void TradeOrg::addDistributor(Distributor* distr) {
	distributors.push_back(distr);
	Balance -= distr->getDefBalance();
}

double TradeOrg::BuyProducts(VendorCode vc, double amountOrdered, double* balance, bool wholeSale) { //-1 - недостаточно средств
	double amountToSelling = amountOrdered;
	double curBalance = *balance;
	//search of distr
	for (Distributor* dist : distributors)
	{
		if (wholeSale) {
			try {
				Store* str = (Store*)dist;
				if (str->checkAvailabilityVC(vc))
				{
					double ordered = str->orderProducts(amountToSelling, vc);
					double ordPrice = str->calculateSum(ordered, vc);
					if (ordPrice < curBalance)
					{
						str->sell(vc, ordered);
						curBalance -= ordPrice;
						amountToSelling -= ordered;
						if (amountToSelling <= 1E-5) {
							*balance = curBalance;
							return amountOrdered;
						}
					}
					else {
						*balance = curBalance;
						return -1;
					}
				}
			}
			catch (...) {
			}
		}else{
			try {
				Storage* strg = (Storage*)dist;
				if (strg->checkAvailabilityVC(vc))
				{
					double ordered = strg->orderProducts(amountToSelling, vc);
					double ordPrice = strg->calculateSum(ordered, vc);
					if (ordPrice < curBalance)
					{
						strg->sell(vc, ordered);
						curBalance -= ordPrice;
						amountToSelling -= ordered;
						if (amountToSelling <= 1E-5) {
							*balance = curBalance;
							return amountOrdered;
						}
					}
					else {
						*balance = curBalance;
						return -1;
					}
				}
			}
			catch (...) {
			}
		}
	}
	*balance = curBalance;
	return amountOrdered - amountToSelling;
}

void TradeOrg::collectProfit() {
	for (Distributor* distr : distributors)
	{
		Balance += distr->getProfit();
	}
}