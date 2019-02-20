
#include "CarBase.h"

class UsedCar : public CarBase
{
public:
	int GetMlg() const;
	UsedCar();
	UsedCar(string carCategory, int carMileage, string carVin, bool carLeased, string carModel, string carMake,  int carYear, float carPrice);

	~UsedCar();

	virtual void print() const;
	virtual string textFilePrint() const;


protected:
	int Mileage;

};
