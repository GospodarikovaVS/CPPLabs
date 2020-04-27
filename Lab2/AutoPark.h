#pragma once
#include <vector>
#include "Truck.h"
class AutoPark
{
public:
	double chooseTrucks(double amount, VendorCode vc, double price);
	void addTruck(Truck truck);
	void addTruck(double volume, double speed, double price);

private:
	std::vector<Truck> trucks;
};

