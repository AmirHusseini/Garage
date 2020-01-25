#include<vector>
#include"Fordon.h"

class myGarage
{
public:
	myGarage(int capacity);
	~myGarage();
	//void open();
	void showMenu();
	int processChoice();
	bool addVehicle();
	Vehicle* createVehicle();
	Vehicle* removeVehicle(string reg);
	void ShowVehicleList();
	void searchVehicleWithRegNumber();
	void searchVehicleWithColor();
	void searchVehicleWithWheels();
	void searchVehicleWithPassangers();
	void printVehicles(std::vector<Vehicle*> vehicles);
	void ShowAirQuality();
private:
	const int iCapacity = 0;
	std::vector<Vehicle*> iVehicles;
};





