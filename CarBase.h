#ifndef CARBASEH
#define CARBASEH


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CarBase
{

public:

	CarBase();
	CarBase(string carCategory, string carVin, bool carLeased, string carModel, string carMake,  int carYear, float carPrice);

	virtual ~CarBase();

	string getCarCtgr() const;
	void setCtgr(string);
	string getCarV() const;
	bool getLsd() const;
	void setLsd(bool);
	string getCarMdl() const;
	string getCarMk() const;
	int getCarYr() const;
	float getCarPrc() const;
	
	virtual string textFilePrint() const = 0;
	virtual void print() const = 0;


protected:
	string Category;
	string VIN;
	bool Leased;
	string Model;
	string Make;
	int Year;
	float Price;
};

#endif // !CARBASEH