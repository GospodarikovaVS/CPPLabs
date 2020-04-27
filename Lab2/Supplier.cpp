#include "Supplier.h"

VCSet Supplier::supplyVCSet(VendorCode vc, double amount, double price) {
	return VCSet(vc, amount, price);
}