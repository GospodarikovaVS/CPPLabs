#include "Product.h"
#include <string>

Product::Product() {
	this->price = 0.0;
	this->title = "undefined";
}

Product::Product(double price, std::string newTitle) {
	this->price = price;
	this->title = newTitle;
}

double Product::buyShares(int count) { 
	return this->price * count; 
}

double Product::getPrice() {
	return this->price;
}

std::string Product::getTitle() {
	return title;
}

void Product::setTitle(std::string newTitle) {
	title = newTitle;
}

