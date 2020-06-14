#include "TradeOrg.h"
#include <vector>
#include "Distributor.h"
#include "Store.h"
#include "Storage.h"
#include "Supplier.h"

TradeOrg::TradeOrg(double balance) {
	Balance = balance;
}

VCSet* TradeOrg::orderVCS(VendorCode vc, double amountOrdered, double price) {
	Supplier sup = Supplier();
	VCSet* order = sup.supplyVCSet(vc, amountOrdered, price);
	Balance -= price * order->getCurAmount();
	return order;
}

void TradeOrg::addDistributor(Distributor* distr) {
	distributors.push_back(distr);
	Balance -= distr->getDefBalance();
}

vector<VCSet> TradeOrg::BuyProducts(VendorCode vc, double amountOrdered, double* balance, bool wholeSale) { //-1 - недостаточно средств
	vector<VCSet> vecVCSet;
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
						for(VCSet v : str->sell(vc, ordered)) {
							vecVCSet.push_back(v);
						}
						curBalance -= ordPrice;
						amountToSelling -= ordered;
						if (amountToSelling <= 1E-5) {
							*balance = curBalance;
							return vecVCSet;
						}
					}
					else {
						*balance = curBalance;
						return vecVCSet;
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
						for (VCSet v : strg->sell(vc, ordered)) {
							vecVCSet.push_back(v);
						}
						curBalance -= ordPrice;
						amountToSelling -= ordered;
						if (amountToSelling <= 1E-5) {
							*balance = curBalance;
							return vecVCSet;
						}
					}
					else {
						*balance = curBalance;
						return vecVCSet;
					}
				}
			}
			catch (...) {
			}
		}
	}
	*balance = curBalance;
	return vecVCSet;
}

void TradeOrg::collectProfit() {
	for (Distributor* distr : distributors)
	{
		Balance += distr->getProfit();
	}
}