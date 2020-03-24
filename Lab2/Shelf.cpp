#include "Shelf.h"
#include "Product.h"

Shelf::Shelf() {
	this->product = Product();
	count = 0;
}//articule + accept

Shelf::Shelf(Product prod) {
	this->product = prod;
	count = 0;
}

Shelf::Shelf(Product prod, int count) {
	this -> product = prod;
	this -> count = count;
}


int Shelf::checkBalance() {
	return count;
}

bool Shelf::checkType(std::string curTitle) {
	return curTitle == this->product.getTitle();
}

bool Shelf::checkType(Product prod) {
	return prod.getTitle() == this->product.getTitle();
}
