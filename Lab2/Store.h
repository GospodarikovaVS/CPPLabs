#pragma once
#include "Distributor.h"
#include "VendorCode.h"
#include <vector>
#include "Shelf.h"
class Store :
	public Distributor
{
public:
	Store();

private:
	const double defBalance = 1000.0;

	
};

