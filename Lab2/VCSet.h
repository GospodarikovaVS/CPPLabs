#pragma once
#include "VendorCode.h"
class VCSet
{
public:
	VCSet(VendorCode vc, int amount, double price);
	int buyAmount(int amount);
	VendorCode getVC();
	void setPrice(double price);
	double getPrice();
	int getCurAmount();
	int getDefAmount();
	void increaseAmount(int increasment);
	bool checkType(VendorCode vc);


private:
	VendorCode vc;
	double price; // если на развес - за кг/литр, иначе за штуку
	int amount; // количество штук или кг/литров
	int defAmount; // количество штук или кг/литров по-умолчанию
};

