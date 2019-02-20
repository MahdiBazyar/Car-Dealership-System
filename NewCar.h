

#include "CarBase.h"

class NewCar : public CarBase
{
public:
	NewCar();
	NewCar(string carCategory, string carWarranry, string carVin, bool carLeased, string carModel, string carMake, int carYear, float carPrice);

	~NewCar();

	string GetWarranty() const;

	virtual void print() const;
	virtual string textFilePrint() const;


protected:
	string Warranty;
};

