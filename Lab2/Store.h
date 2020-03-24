#pragma once
#include "Distributor.h"
#include "Product.h"
#include <vector>
#include "Shelf.h"
class Store :
	public Distributor
{
public:

private:
	std::vector<Shelf> shelfs;

	double buyProducts(int number, Product prod) {
		int numReal = number;
		if (Budget >= numReal * prod.price)
			Budget -= numReal * prod.price;
		else {
			collectProfit();
			if (Budget >= numReal * prod.price)
				Budget -= numReal * prod.price;
			else {
				numReal = (int)Budget / (int)prod.price;
				Budget -= numReal * prod.price;
			}
		}
		//order truck, which will deliver products(MayBe in storage with buffer)
		return numReal;
	}
};

