#pragma once
#include <string>
class Product
{
public:
	Product();
	Product(double price, std::string newTitle);
	double buyShares(int count);
	double getPrice();
	std::string getTitle();
	void setTitle(std::string newTitle);
	~Product() {};

private:
	double price;
	std::string title;
};

