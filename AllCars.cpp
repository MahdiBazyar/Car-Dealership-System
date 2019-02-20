//Mahdi Bazyar
//CSC 2100 Final Project
//Date: 12/05/2018

#include "AllCars.h"


AllCars::AllCars()
{
	TextFile = "TextFile.txt";
}


AllCars::AllCars(string myTextFile)
{
	TextFile = myTextFile;
}

AllCars::~AllCars()
{
	ofstream OutPut;
	OutPut.open("OutPutFile.txt");

	if (!OutPut)
		throw logic_error(" Sorry, we Can not open your output file");

	for (it = CarVector.begin(); it != CarVector.end(); it++)
	{
		OutPut << (*it)->textFilePrint();
	}


	for (it = CarVector.begin(); it != CarVector.end(); it++)
	{
		delete (*it);
	}

	OutPut.close();
}


void AllCars::CarMenu()
{
	int SearchInventory, Sell, Lease, Return, Add, Exit;
	cout << endl << " *** Car Menu List *** " <<
		endl << "1 - Search Inventory" <<
		endl << "2 - Sell Cars" <<
		endl << "3 - Lease Cars" <<
		endl << "4 - Return A Leased Car" <<
		endl << "5 - Add Cars to Inventory" <<
		endl << "6 - Exit" <<
		endl;
}


void AllCars::Content()
{
	ifstream input;
	string Category, Warranty, Mileage, VIN, Leased, Model, Make, Year, Price, Trash;
	bool tempLeased;
	int tempMileage;
	int tempYear;
	float tempPrice;
	input.open(TextFile);

	if (!input)
		throw logic_error("Sorry, we Can Not Open your Input File.");

	try
	{
		while (input.peek() != EOF)
		{

			getline(input, Category);
			if (Category == "New")
				getline(input, Warranty);

			else if (Category == "Used")
			{
				getline(input, Mileage);
				tempMileage = stoi(Mileage);
			}
			else
				throw logic_error("Category seems false.");

			getline(input, VIN);

			getline(input, Leased);
			if (Leased == "true")
				tempLeased = true;
			else if (Leased == "false")
				tempLeased = false;
			else
				throw logic_error(" Input is not correct.");

			getline(input, Model);
			getline(input, Make);
			

			getline(input, Year);
			tempYear = stoi(Year);

			getline(input, Price);
			tempPrice = stof(Price);

			

			if (Category == "New")
				CarVector.push_back(new NewCar(Category, Warranty, VIN, tempLeased, Model, Make,  tempYear, tempPrice));
			else
				CarVector.push_back(new UsedCar(Category, tempMileage, VIN, tempLeased, Model, Make,  tempYear, tempPrice));

			getline(input, Trash);
			getline(input, Trash);
		}
		input.close();
	}
	catch (...)
	{
		throw logic_error(" strings cannot be converted to numbers.");
		input.close();
	}

}


void AllCars::SearchInvetory()
{
	int searchItem;
	string ByCarCategory, ByCarVIN, ByCarModel, ByCarMake;
	bool Found = false;

	cout << endl << "If you Would Like to Search in the Inventory, you can choose any option: "
		<< endl << "1 : Search by category of Car"
		<< endl << "2 : Search by Vin of Car"
		<< endl << "3 : Search by Model of Car"
		<< endl << "4 : Search by Make of Car" << endl;
	cin >> searchItem;

	if (searchItem == 1)
	{
		cout <<  endl << "Please Input the category of the Car(New / Used): " << endl;
		cin >> ByCarCategory;
		

		for (it = CarVector.begin(); it != CarVector.end(); it++)
		{
			if ((*it)->getCarCtgr() == ByCarCategory)
			{
				(*it)->print();
				Found = true;
			}
		}

		if (!Found)
			cout << endl << "Sorry, category of Car is not Found." << endl;
	}

	else if (searchItem == 2)
	{
		cout << endl << "Please Input the Vin of Car: " << endl;
		cin >> ByCarVIN;
		

		for (it = CarVector.begin(); it != CarVector.end(); it++)
		{
			if ((*it)->getCarV() == ByCarVIN)
			{
				(*it)->print();
				Found = true;
			}
		}



		if (!Found)
			cout << endl << "Sorry, Vin of Car is not Found." << endl;
	}

	else if (searchItem == 3)
	{
		cout << endl << "Please Input the Model of the Car: " << endl;
		cin >> ByCarModel;
		

		for (it = CarVector.begin(); it != CarVector.end(); it++)
		{
			if ((*it)->getCarMdl() == ByCarModel)
			{
				(*it)->print();
				Found = true;
			}
		}

		if (!Found)
			cout << endl << "Sorry, Model of Car is not Found." << endl;
	}

	else if (searchItem == 4)
	{
		cout << endl << "Please Input the Make of the Car: " << endl;
		cin >> ByCarMake;

		for (it = CarVector.begin(); it != CarVector.end(); it++)
		{
			if ((*it)->getCarMk() == ByCarMake)
			{
				(*it)->print();
				Found = true;
			}

		}

		if (!Found)
			cout << endl << "Sorry, Make of Car is not Found." << endl;
	}

	else
		cout << endl << "Your Input is not Correct" << endl;
}



void AllCars::SellCar()
{
	cout << endl << "*** Selling A Car *** " << endl;
	string searchItem;
	bool Found = false;
	cout << endl << "Please Input the VIN: " << endl;
	cin >> searchItem;

	for (it = CarVector.begin(); it != CarVector.end(); it++)
	{
		if ((*it)->getCarV() == searchItem)
		{
			cout << endl << "You've sold a car with the following features; " << endl;
			(*it)->print();
			delete (*it);
			CarVector.erase(it);
			Found = true;
			return;

		}
	}

	if (!Found)
	{
		cout << endl << "Sorry, Vin of the Car is not Found." << endl << endl;
	}
}


void AllCars::LeaseCar()
{
	cout << endl << "*** Leaseing A Car ***" << endl;

	string searchItem;


	cout << endl << "Please Input the VIN: " << endl;
	cin >> searchItem;

	for (it = CarVector.begin(); it != CarVector.end(); it++)
	{
		if ((*it)->getCarV() == searchItem)
		{
			if ((*it)->getLsd())
			{
				cout << endl << "Sorry, This Car is Leased before. " << endl;
			}
			else
			{
				cout << endl << " Leasing the Car is done successfully" << endl;
				(*it)->setLsd(true);
			}
			(*it)->print();

			return;
		}
	}
	cout << endl << "Sorry, Lease of Car is not successful." << endl << endl;
}


void AllCars::ReturnALeasedCar()
{
	cout << endl << "*** Returning A Leased Car ***" << endl;

	string searchItem;
	bool Found = false;

	cout << endl << "Please Input the VIN: " << endl;
	cin >> searchItem;

	for (it = CarVector.begin(); it != CarVector.end(); it++)
	{
		if ((*it)->getCarV() == searchItem)
		{
			if ((*it)->getLsd())
			{
				cout << endl << "Returning the Car is done successfully" << endl << endl;
			}
			else
			{
				cout << endl << "Sorry, This Car is Returned before." << endl << endl;
				(*it)->setCtgr("Used");
				(*it)->setLsd(false);
			}
			(*it)->print();

			Found = true;
		}
	}

	if (!Found)
	{
		cout << endl << "Sorry, a Car with this VIN is not Found." << endl << endl;
	}
}



void AllCars::AddCars()
{
	cout << endl << "*** Adding Cars to Inventory ***" << endl;


	string Category, Warranty, Mileage, VIN, Leased, Model, Make, Year, Price, trash;
	int tempMileage = 0;
	bool  tempLeased = false;
	int tempYear;
	float tempPrice;

	getline(cin, trash);
	cout << endl << "Please Input Your Vin of Car: " << endl;
	getline(cin, VIN);

	for (it = CarVector.begin(); it != CarVector.end(); it++)
	{
		if ((*it)->getCarV() == VIN) {
			cout << endl << "Sorry, You cannot add this VIN because it is already in our System." << endl;
			return;
		}
	}

	cout << endl << "Please Input your Category of Car(new/used): " << endl;
	getline(cin, Category);
	while ((Category != "New") && (Category != "Used"))
	{

		cout << endl << "Could you Try one more time. Try to Input New or Used: " << endl;
		getline(cin, Category);
	}
	

	if (Category == "New")
	{
		cout << endl << "Please Input Your Warranty of the Car: " << endl;
		getline(cin, Warranty);
	}
	else if (Category == "Used")
	{
		cout << endl << "Please Input Your Mileage of Car:" << endl;
		getline(cin, Mileage);
		tempMileage = stoi(Mileage);
	}


	cout << endl << "Please Input Your Model of Car: " << endl;
	getline(cin, Model);

	cout << endl << "Please Input Your Make of Car: " << endl;
	getline(cin, Make);

	cout << endl << "Please Input Your Year of Car: " << endl;
	getline(cin, Year);
	tempYear = stoi(Year);

	cout << endl << "Please Input Your Price of Car: " << endl;
	getline(cin, Price);
	tempPrice = stof(Price);

	if (Category == "New")
		CarVector.push_back(new NewCar(Category, Warranty, VIN, tempLeased, Model, Make,  tempYear, tempPrice));
	else
		CarVector.push_back(new UsedCar(Category, tempMileage, VIN, tempLeased, Model, Make,  tempYear, tempPrice));

	(*(CarVector.end() - 1))->print();
	cout << endl;
}




int main()
{
	int Menu;

	try
	{
		AllCars CarObj;
		CarObj.Content();


		while (true)
		{
			CarObj.CarMenu();


			cout << endl << "Please choose an Item from the Menu: " << endl;
			cin >> Menu;

			switch (Menu)
			{
			case 1:
				CarObj.SearchInvetory();
				break;
			case 2:
				CarObj.SellCar();
				break;
			case 3:
				CarObj.LeaseCar();
				break;
			case 4:
				CarObj.ReturnALeasedCar();
				break;
			case 5:
				CarObj.AddCars();
				break;
			case 6:
				return 0;

			default:
				cout << endl << "Sorry, Input is not Correct" << endl;
			}
		}

	}
	catch (logic_error LogErr)
	{
		cout << LogErr.what() << endl;
	}
	return 0;
}