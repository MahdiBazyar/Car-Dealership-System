//Mahdi Bazyar
//CSC 2100 Final Project
//Date: 12/05/2018

#include "UsedCar.h"

int UsedCar::GetMlg() const
{
	return Mileage;
}


UsedCar::UsedCar()
	:CarBase("", "", "", false, "", 0, 0.0)
{
	Mileage = 0;
}


UsedCar::UsedCar(string carCategory, int carMileage, string carVin, bool carLeased, string carModel, string carMake,  int carYear, float carPrice)
	:CarBase(carCategory, carVin, carLeased, carModel, carMake, carYear, carPrice)


{
	Mileage = carMileage;
}


UsedCar::~UsedCar() {}



void UsedCar::print() const
{
	cout << endl << "Category: " << Category << endl 
		<< "Mileage: " << Mileage << endl 
		<< "VIN: " << VIN << endl
		<< "Leased: " << Leased << endl
		<< "Model: " << Model << endl 
		<< "Make: " << Make << endl
		<< "Year: " << Year << endl
		<< "Price: $" << Price  << endl << endl;
}



string UsedCar::textFilePrint() const
{
	string tempTxt;
	string StrLeased;

	if (Leased == true)
		StrLeased = "true";
	else
		StrLeased = "false";

	tempTxt = Category + "\n" + to_string(Mileage) + "\n" + VIN + "\n" + StrLeased + "\n" + Make + "\n" + Model + "\n" + to_string(Year) + "\n" + to_string(Price) + "\n\n";

	return tempTxt;

}
