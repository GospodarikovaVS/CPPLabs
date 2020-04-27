#pragma once
#include "VCSet.h"
class Truck
{
public:
	Truck(double volume, double speed, double price);
	double getVolume();
	bool checkState();
	void changeState(bool st);
	double deliverVCSetsFromStorage();
	VCSet deliverVCSetsFromSupplier(VendorCode vc, double amount, double price);


private:
	double volume;
	double speed;
	double price;
	bool state;

};

