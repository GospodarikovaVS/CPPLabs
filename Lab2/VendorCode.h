#pragma once
#include <string>
class VendorCode
{
public:
	VendorCode();
	VendorCode(std::string newTitle, double weight, double volume, 
		bool isLiquid, bool byWeight, bool fragility,
		std::string color, std::string describtion);
	VendorCode(std::string newTitle);
	VendorCode(std::string newTitle, double weight, double volume,
		bool isLiquid, bool byWeight);
	std::string getTitle();
	void setTitle(std::string newTitle);
	bool getVolWeightParams(double* weight, double* volume);
	~VendorCode() {};

private:
	std::string codeSKU;
	std::string title;
	//������-������� ��������� ����� ����� ������(������� ��������)
	double volume; //����� - �^3; �������� - �����
	double weight; //��
	bool byWeight; // true - ����� �� ������; false - ����� ��������
	bool isLiquid; // true - ��������; false - ����� �����

	//������
	std::string color;
	bool fragility;// true - ����� �������; false - ����� �� ��������� �������(����� ���� ����� ��� ���������)
	std::string desribtion;

};

