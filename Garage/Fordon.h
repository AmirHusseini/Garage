
#include<string>
using namespace std;

struct vehicleDetails
{
	string vehicleName;
	string regNumber;
	string color;
	int numOfWheels = 0;
	int numOfPassengers = 0;
};

class Vehicle
{
public:
	Vehicle(vehicleDetails details);
	~Vehicle();

	string getVehicleName() { return iVehicleName; }
	string getRegNumber() { return iRegNumber; }
	string getColor() { return iColor; }
	int getNumOfWheels() { return iNumOfWheels; }
	int getNumOfPassengers() { return iNumOfPassengers; }

	// polymorphism
	virtual string getVehicleCategory() = 0;//to ask and show the specific vehicle in show list
	virtual void printVehicleCreated() = 0;//to print the added vehicle
	virtual void printVehicleRemoved() = 0;//to print the removed vehicle

	virtual bool isPollutingVehicle() { return true; } // to check the vehicle if is creating pollution (it should not be electric or cycles)

protected:
	// general properties
	string iVehicleName;
	string iRegNumber;
	string iColor;
	int iNumOfWheels = 0;
	int iNumOfPassengers = 0;
};

class Car : public Vehicle
{
private:
	// Constructor kept private and object created using create method
	Car(vehicleDetails details, bool isConvertible, bool isElectric);
public:
	~Car();

	// Static function used to create object of class 
	// dont need object to call this function
	static Vehicle* create(vehicleDetails details);

	// polymorphism
	virtual string getVehicleCategory() { return "Car"; }
	virtual void printVehicleCreated();
	virtual void printVehicleRemoved();
	virtual bool isPollutingVehicle() { return !iIsElectricCar; }
private:
	// specific properties
	bool iIsConvertibleCar = false;
	bool iIsElectricCar = false;
};

class Truck : public Vehicle
{
private:
	// Constructor kept private and object created using create method
	Truck(vehicleDetails details, bool isOpen, bool isHeavy);
public:
	~Truck();

	// Static function used to create object of class 
	// dont need object to call this function
	static Vehicle* create(vehicleDetails details);

	// polymorphism
	virtual string getVehicleCategory() { return "Truck"; }
	virtual void printVehicleCreated();
	virtual void printVehicleRemoved();

private:
	// specific properties
	bool isOpen = false;
	bool isHeavy = false;
};

class Bus : public Vehicle
{
private:
	// Constructor kept private and object created using create method
	Bus(vehicleDetails details, bool isLongRoute, bool isEco);
public:
	~Bus();

	// Static function used to create object of class 
	// dont need object to call this function
	static Vehicle* create(vehicleDetails details);

	// polymorphism
	virtual string getVehicleCategory() { return "bus"; }
	virtual void printVehicleCreated();
	virtual void printVehicleRemoved();

private:
	// specific properties
	bool isLongRoute = false;
	bool isEco = false;
};

class Bike : public Vehicle
{
private:
	// Constructor kept private and object created using create method
	Bike(vehicleDetails details, bool isSportBike, bool isElectric);
public:
	~Bike();

	// Static function used to create object of class 
	// dont need object to call this function
	static Vehicle* create(vehicleDetails details);

	// polymorphism
	virtual string getVehicleCategory() { return "Bike"; }
	virtual void printVehicleCreated();
	virtual void printVehicleRemoved();
	virtual bool isPollutingVehicle() { return !iIsElectricBike; }

private:
	// specific properties
	bool iIsSportBike = false;
	bool iIsElectricBike = false;
};

class Cycle : public Vehicle
{
private:
	// Constructor kept private and object created using create method
	Cycle(vehicleDetails details, bool isSport, bool isElectric);
public:
	~Cycle();

	// Static function used to create object of class 
	// dont need object to call this function
	static Vehicle* create(vehicleDetails details);

	// polymorphism
	virtual  string getVehicleCategory() { return "Cycle"; }
	virtual void printVehicleCreated();
	virtual void printVehicleRemoved();
	virtual bool isPollutingVehicle() { return false; }
private:
	// specific properties
	bool iIsSport = false;
	bool iIsElectricCycle = false;
};

