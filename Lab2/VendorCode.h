#pragma once
#include <string>
class VendorCode
{
public:
	VendorCode();
	VendorCode(std::string newTitle, double weight, double volume, 
		bool isLiquid, bool byWeight, bool fragility,
		std::string color, std::string describtion);
	VendorCode(std::string newTitle, double weight, double volume,
		bool isLiquid, bool byWeight);
	VendorCode(std::string newTitle);

	std::string getCodeSKU();
	std::string getTitle();
	std::string getColor();
	std::string getDescription();
	bool getIsLiquid();
	bool getFragility();

	void setTitle(std::string newTitle);
	void setVolume(double volume);
	void setWeight(double weight);
	void setByWeight(bool byWeight);
	void setIsLiquid(bool isLiquid);
	void setColor(std::string color);
	void setFragility(bool fragility);
	void setDescription(std::string description);

	bool getVolWeightParams(double* weight, double* volume);
	~VendorCode() {};

private:
	std::string codeSKU;
	std::string title;
	//Объёмо-весовые параметры одной штуки товара(единицы артикула)
	double volume; //сухой - м^3; жидкость - литры
	double weight; //кг
	bool byWeight; // true - товар на развес; false - товар поштучно
	bool isLiquid; // true - жидкость; false - сухой товар

	//Другие
	std::string color;
	bool fragility;// true - товар хрупкий; false - товар не считается хрупким(может быть важно для перевозки)
	std::string desribtion;

};

