#pragma once
#include "VendorCode.h"
class VCSet
{
public:
	VCSet(VendorCode vc, double amount, double price);
	VendorCode getVC();
	void setPrice(double price);
	double getPrice();
	double getCurAmount();
	double getDefAmount();
	void increaseAmount(double increasment);
	bool checkType(VendorCode vc);


private:
	VendorCode vc;
	double price; // если на развес - за кг/литр, иначе за штуку
	double amount; // количество штук или кг/литров
	double defAmount; // количество штук или кг/литров по-умолчанию
};

