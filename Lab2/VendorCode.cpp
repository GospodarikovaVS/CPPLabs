#include "VendorCode.h"
#include <string>

static int curSKU = 0;

VendorCode::VendorCode() {
	this->title = "undefined";
	this->codeSKU = curSKU++;
}

VendorCode::VendorCode(std::string newTitle, double weight, double volume,
	bool isLiquid, bool byWeight, bool fragility,
	std::string color, std::string describtion) {
	this->byWeight = byWeight;
	this->isLiquid = isLiquid;
	this->fragility = fragility;

	this->desribtion = describtion;
	this->color = color;

	this->weight = weight;
	this->volume = volume;
	this->title = newTitle;
	this->codeSKU = curSKU++;
}

VendorCode::VendorCode(std::string newTitle, double weight, double volume,
	bool isLiquid, bool byWeight) {
	this->byWeight = byWeight;
	this->isLiquid = isLiquid;
	this->fragility = false;

	this->desribtion = "";
	this->color = "";

	this->weight = weight;
	this->volume = volume;
	this->title = newTitle;
	this->codeSKU = curSKU++;
}

VendorCode::VendorCode(std::string newTitle) {
	this->title = newTitle;
	this->codeSKU = curSKU++;

	this->byWeight = NULL;
	this->isLiquid = NULL;
	this->fragility = NULL;

	this->desribtion = "";
	this->color = "";

	this->weight = NULL;
	this->volume = NULL;
}


bool VendorCode::getVolWeightParams(double* weight, double* volume) {
	if (byWeight)
		return byWeight;
	*weight = this->weight;
	*volume = this->volume;
	return byWeight;
}

std::string  VendorCode::getCodeSKU() 
{
	return codeSKU;
}
std::string  VendorCode::getTitle()
{
	return title;
}
std::string  VendorCode::getColor()
{
	return color;
}
std::string  VendorCode::getDescription()
{
	return desribtion;
}
bool  VendorCode::getIsLiquid()
{
	return isLiquid;
}
bool  VendorCode::getFragility()
{
	return fragility;
}


void VendorCode::setTitle(std::string newTitle) {
	title = newTitle;
}
void VendorCode::setVolume(double volume)
{
	this->volume = volume;
}
void VendorCode::setWeight(double weight)
{
	this->weight = weight;
}
void VendorCode::setByWeight(bool byWeight)
{
	this->byWeight = byWeight;
}
void VendorCode::setIsLiquid(bool isLiquid)
{
	this->isLiquid = isLiquid;
}
void VendorCode::setColor(std::string color)
{
	this->color = color;
}
void VendorCode::setFragility(bool fragility)
{
	this->fragility = fragility;
}
void VendorCode::setDescription(std::string description)
{
	this->desribtion = description;
}
