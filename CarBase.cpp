#include "CarBase.h"


CarBase::CarBase()
{
	Category = "";
	VIN = "";
	Leased = false;
	Model = "";
	Make = "";
	Year = 0;;
	Price = 0.0;
}

CarBase::CarBase(string carCategory, string carVin, bool carLeased, string carModel, string carMake,  int carYear, float carPrice)
{
	Category = carCategory;
	VIN = carVin;
	Leased = carLeased;
	Model = carModel;
	Make = carMake;
	Year = carYear;
	Price = carPrice;
}


CarBase::~CarBase() {}

string CarBase::getCarCtgr() const
{
	return Category;
}

void CarBase::setCtgr(string category)
{
	Category = category;
}

string CarBase::getCarV() const
{
	return VIN;
}

bool CarBase::getLsd() const
{
	return Leased;
}

void CarBase::setLsd(bool leased)
{
	Leased = leased;
}

string CarBase::getCarMdl() const
{
	return Model;
}

string CarBase::getCarMk() const
{
	return Make;
}

int CarBase::getCarYr() const
{
	return Year;
}

float CarBase::getCarPrc() const
{
	return Price;
}