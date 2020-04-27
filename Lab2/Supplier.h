#pragma once
#include "VCSet.h"
#include "VendorCode.h"
class Supplier
{
public:
	VCSet supplyVCSet(VendorCode vc, double amount, double price);
};

