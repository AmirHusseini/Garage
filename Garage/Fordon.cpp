#include <iostream>
#include<string>
#include"Fordon.h"

// class definition in cpp file

//==================Vehicle Class==================================
Vehicle::Vehicle(vehicleDetails details)
{
	iRegNumber = details.regNumber;
	iColor = details.color;
	iNumOfWheels = details.numOfWheels;
	iNumOfPassengers = details.numOfPassengers;
	iVehicleName = details.vehicleName;
}

Vehicle::~Vehicle()
{
}

//==================Car Class======================================

Car::Car(vehicleDetails details, bool convertible, bool electric)
	:Vehicle(details)
{
	iIsConvertibleCar = convertible;
	iIsElectricCar = electric;
}

Car::~Car()
{

}

Vehicle* Car::create(vehicleDetails details)
{
	int isConvertible, isElectric;
	cout << "Is car convertible: \n1.Yes or 0.No: ";
	cin >> isConvertible;
	cout << "Is car electric: \n1.Yes or 0.No : ";
	cin >> isElectric;

	Vehicle* newVehicle = new Car(details, isConvertible, isElectric);
	return newVehicle;
}

void Car::printVehicleCreated()
{
	cout <<"Car is parked in the parking " << endl << endl;
}

void Car::printVehicleRemoved()
{
	cout << "Car is removed from parking " << endl << endl;
}
//==================Truck class======================================
Truck::Truck(vehicleDetails details, bool isOpen, bool isHeavy)
	:Vehicle(details), isOpen(isOpen), isHeavy(isHeavy)
{

}

Truck::~Truck()
{

}
Vehicle* Truck::create(vehicleDetails details)
{
	int isOpen, isHeavy;
	cout << "Is it open truck: \n1.Yes or 0.No : ";
	cin >> isOpen;
	cout << "Is it heavy truck: \n1.Yes or 0.No : ";
	cin >> isHeavy;

	Vehicle* newVehicle = new Truck(details, isOpen, isHeavy);
	return newVehicle;
}

void Truck::printVehicleCreated()
{
	cout << "Truck is parked in the parking " << endl << endl;
}

void Truck::printVehicleRemoved()
{
	cout << "Truck is removed from parking " << endl << endl;
}
//==================Bus class=========================================
Bus::Bus(vehicleDetails details, bool isLongRoute, bool isEco)
	:Vehicle(details), isLongRoute(isLongRoute), isEco(isEco)
{

}

Bus::~Bus()
{

}
Vehicle* Bus::create(vehicleDetails details)
{
	int isLongRoute, isEco;
	cout << "Is it LongRoute: \nBus 1.Yes or 0.No : ";
	cin >> isLongRoute;
	cout << "Is it Eco Bus: \n1.Yes or 0.No : ";
	cin >> isEco;

	Vehicle* newVehicle = new Bus(details, isLongRoute, isEco);
	return newVehicle;
}

void Bus::printVehicleCreated()
{
	cout << "Bus is parked in the parking " << endl << endl;
}

void Bus::printVehicleRemoved()
{
	cout << "Bus is removed from parking " << endl << endl;
}

//==================Bike class=======================================

Bike::Bike(vehicleDetails details, bool isSportBike, bool isElectric)
	:Vehicle(details)
{
	iIsSportBike = isSportBike;
	iIsElectricBike = isElectric;
	iNumOfWheels = 2;
	iNumOfPassengers = 2;
}

Bike::~Bike()
{

}

Vehicle* Bike::create(vehicleDetails details)
{
	int isSport, isElectric;
	cout << "Is it sport Motorcycle: \n1.Yes or 0.No : ";
	cin >> isSport;
	cout << "Is it electric Motorcycle: \n1.Yes or 0.No : ";
	cin >> isElectric;

	Vehicle* newVehicle = new Bike(details, isSport, isElectric);
	return newVehicle;
}

void Bike::printVehicleCreated()
{
	cout << "Motorcycle is parked in the parking " << endl << endl;
}

void Bike::printVehicleRemoved()
{
	cout << "Motorcycle is removed from parking " << endl << endl;
}

//==================Cycle Class======================================

Cycle::Cycle(vehicleDetails details, bool isSport, bool isElectric)
	:Vehicle(details), iIsSport(isSport), iIsElectricCycle(isElectric)
{

}

Cycle::~Cycle()
{

}

Vehicle* Cycle::create(vehicleDetails details)
{
	int isSport, isElectric;
	cout << "Is Cycle sport: \n1.Yes or 0.No : ";
	cin >> isSport;
	cout << "Is Cycle electric: \n1.Yes or 0.No : ";
	cin >> isElectric;

	Vehicle* newVehicle = new Cycle(details, isSport, isElectric);
	return newVehicle;
}

void Cycle::printVehicleCreated()
{
	cout << "Cycle is parked in the parking " << endl << endl;
}

void Cycle::printVehicleRemoved()
{
	cout << "Cycle is removed from parking " << endl << endl;
}