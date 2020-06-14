#include "Supplier.h"

VCSet* Supplier::supplyVCSet(VendorCode vc, double amount, double price) {
	VCSet* vcs = new VCSet(vc, amount, price);
	return vcs;
}