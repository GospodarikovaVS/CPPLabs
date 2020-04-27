#include "AutoPark.h"

double AutoPark::chooseTrucks(double amount, VendorCode vc, double price) {
	double finPrice = 0.0;
	double vol = 0, weight = 0;
	double curVol = 0;
	bool moreThenMost = true, checker = true;
	if (vc.getVolWeightParams(&weight, &vol))
		curVol = amount;
	else curVol = amount * vol;
	while (moreThenMost) {
		double tv = 0.0;
		for (Truck t : trucks) {
			if (t.checkState() && t.getVolume() > tv)
				tv = t.getVolume();
		}
		moreThenMost = tv < curVol;
		if (moreThenMost) {
			for (Truck t : trucks) {
				if (checker && t.getVolume() == tv) {
					finPrice += t.deliverVCSetsFromStorage();
					t.changeState(false);
					curVol -= tv;
					checker = false;
				}
			}
		}
	}
	checker = true;
	for (Truck t : trucks) {
		if (checker && t.getVolume() >= curVol) {
			finPrice += t.deliverVCSetsFromStorage();
			t.changeState(false);
			curVol = 0;
			checker = false;
		}
	}
	for (Truck t : trucks) {
		t.changeState(true);
	}
	return finPrice;
}
void AutoPark::addTruck(Truck truck) {
	trucks.push_back(truck);
}
void AutoPark::addTruck(double volume, double speed, double price) {
	trucks.push_back(Truck(volume, speed, price));
}