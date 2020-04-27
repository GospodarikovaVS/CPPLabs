#include "Truck.h"
#include "Supplier.h"

Truck::Truck(double volume, double speed, double price) {
	this->volume = volume;
	this->speed = speed;
	this->price = price;
	state = true;
}
double Truck::deliverVCSetsFromStorage() {
	//delay(1 / speed);

	return price;
}
VCSet Truck::deliverVCSetsFromSupplier(VendorCode vc, double amount, double price) {
	//delay(1 / speed);
	Supplier sup = Supplier();
	return sup.supplyVCSet(vc, amount, price);
}
double Truck::getVolume() {
	return volume;
}
bool Truck::checkState() {
	return state;
}
void Truck::changeState(bool st) {
	state = st;
}