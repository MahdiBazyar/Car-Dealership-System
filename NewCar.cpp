//Mahdi Bazyar
//CSC 2100 Final Project
//Date: 12/05/2018

#include "NewCar.h"
#include "CarBase.h"


NewCar::NewCar()

	:CarBase("","", "", false,"", 0, 0.0)
{
	Warranty = "";
}


NewCar::NewCar(string carCategory, string carWarranry, string carVin, bool carLeased, string carModel, string carMake,  int carYear, float carPrice)

	:CarBase(carCategory, carVin, carLeased, carModel, carMake, carYear, carPrice)
{
	Warranty = carWarranry;
}


NewCar::~NewCar() {}


string NewCar::GetWarranty() const
{
	return Warranty;
}


void NewCar::print() const
{
	cout << endl << "Category: " << Category << endl 
		<< "Warranty: " << Warranty << endl
		<< "VIN: " << VIN << endl 
		<< "Leased: " << Leased << endl
		<< "Model: " << Model << endl
		<< "Make: " << Make << endl
		<< "Year: " << Year << endl
		<< "Price: $" << Price << endl << endl;
}


string NewCar::textFilePrint() const
{
	string tempTxt;
	string StrLeased;

	if (Leased == true)
		StrLeased = "true";
	else
		StrLeased = "false";

	tempTxt = Category + "\n" + Warranty + "\n" + VIN + "\n" + StrLeased +  "\n" + Model + "\n" + Make + "\n" +  to_string(Year) + "\n" + to_string(Price) + "\n\n" ;

	return tempTxt;
}
