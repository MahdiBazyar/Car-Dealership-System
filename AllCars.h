//Mahdi Bazyar
//CSC 2100 Final Project
//Date: 12/05/2018


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "CarBase.h"
#include "NewCar.h"
#include "UsedCar.h"


class AllCars
{
public:
	
	AllCars(string); 
	AllCars();
	
	~AllCars();

	void CarMenu();
	void Content();
	void SearchInvetory();
	void SellCar();
	void LeaseCar();
	void ReturnALeasedCar();
	void AddCars();
	


protected:
	vector <CarBase*> CarVector;
	vector <CarBase*>::iterator it;
	string TextFile;
};

