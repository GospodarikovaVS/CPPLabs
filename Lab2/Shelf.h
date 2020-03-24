#pragma once
#include "Product.h"
#include <string>

class Shelf
{
public:
	Shelf();
	Shelf(Product prod);
	Shelf(Product prod, int count);
	int checkBalance();
	bool checkType(std::string curTitle);
	bool checkType(Product prod);
	~Shelf() {};

private:
	int count;
	Product product;

};

