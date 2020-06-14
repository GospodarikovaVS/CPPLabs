#pragma once
#include "VendorCode.h"
#include <ctime>

class VCSet
{
public:
	VCSet(VendorCode vc, double amount, double price);
	VCSet(VendorCode vc, double amount, double price, time_t t);
	VendorCode getVC();
	void setPrice(double price);
	double getPrice();
	double getCurAmount();
	double getDefAmount();
	void increaseAmount(double increasment);
	bool checkType(VendorCode vc);
	char* getDateAsString();
	time_t getDate();
	VCSet createDaughterVCS(double amount);


private:
	VendorCode vc;
	time_t date;
	double price; // ���� �� ������ - �� ��/����, ����� �� �����
	double amount; // ���������� ���� ��� ��/������
	double defAmount; // ���������� ���� ��� ��/������ ��-���������
};

