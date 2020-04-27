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
	double price; // ���� �� ������ - �� ��/����, ����� �� �����
	double amount; // ���������� ���� ��� ��/������
	double defAmount; // ���������� ���� ��� ��/������ ��-���������
};

