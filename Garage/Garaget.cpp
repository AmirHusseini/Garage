#include"Garaget.h"
#include<iostream>
#include<algorithm>
using namespace std;

myGarage::myGarage(int capacity)
	:iCapacity(capacity)
{

}

myGarage::~myGarage()
{
	for (int i = 0; i < iVehicles.size(); i++)
	{
		delete iVehicles[i];
	}
}

void myGarage::showMenu()
{
	cout << "1.Add Vehicles" << endl;
	cout << "2.Remove the Vehicle" << endl;
	cout << "3.Show Vehicles with free places" << endl;
	cout << "4.Search vehicle with Registration Number" << endl;
	cout << "5.Search vehicle with Color" << endl;
	cout << "6.Search vehicle with number of Wheels" << endl;
	cout << "7.Search vehicle with number of Passangers" << endl;
	cout << "8.Show Air Quality" << endl;
	cout << "0.Exit" << endl;
}

int myGarage::processChoice()
{
	cout << "Parking is created with " << iCapacity << " spaces." << endl << endl;
	int userChoice;
	string reg;
	do
	{
		showMenu();
		cin >> userChoice;
		system("CLS");

	switch (userChoice)
	{
	case 1:
		
		
		if (iVehicles.size() < iCapacity)
		{
			addVehicle();
		}
		else if (iVehicles.size() == iCapacity)
		{
			cout << "The garage is full!" << endl;
		}
		break;
	case 2:
		cout << "Enter the vehicle's Registration number to remove: " << endl << endl;
		cin >> reg;
		removeVehicle(reg);
		break;
	case 3:
		ShowVehicleList();
		break;
	case 4:
		searchVehicleWithRegNumber();
		break;
	case 5:
		searchVehicleWithColor();
		break;
	case 6:
		searchVehicleWithWheels();
		break;
	case 7:
		searchVehicleWithPassangers();
		break;
	case 8:
		ShowAirQuality();
		break;
	default:
		return -1;
		break;
	}
	
	} while (userChoice != 0);
	
};

bool myGarage::addVehicle()
{
	Vehicle* vehicle = createVehicle();
	bool success = false;
	if (vehicle)
	{
		int numOfVehiclesInGarage = iVehicles.size();
		if (numOfVehiclesInGarage < iCapacity)
		{
			iVehicles.push_back(vehicle);
			success = true;
			vehicle->printVehicleCreated();
		}
	}
	return success;
}

Vehicle* myGarage::createVehicle()
{
	int vehicleChoice = 0;
	cout << "\n1.Car \n2.Truck \n3.Bus \n4.Motorcycle \n5.Cycle " << endl;
	cin >> vehicleChoice;
	system("CLS");
	vehicleDetails details;

	cout << "Enter model: ";
	cin >> details.vehicleName;
	cout << "Enter Registration Number: ";
	cin >> details.regNumber;
	cout << "Enter color: ";
	cin >> details.color;
	cout << "Enter number of wheels: ";
	cin >> details.numOfWheels;
	cout << "Enter number of passengers: ";
	cin >> details.numOfPassengers;
	system("CLS");
	Vehicle* newVehicle = nullptr;
	switch (vehicleChoice)
	{
	case 1:
		newVehicle = Car::create(details); //createCar(details);
		break;
	case 2:
		newVehicle = Truck::create(details);
		break;
	case 3:
		newVehicle = Bus::create(details);
		break;
	case 4:
		newVehicle = Bike::create(details);
		break;
	case 5:
		newVehicle = Cycle::create(details);
		break;
	default:
		break;
	}
	return newVehicle;
}

Vehicle* myGarage::removeVehicle(string reg)
{
	if (iVehicles.size() == 0)
	{
		return 0;
	}
	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (reg == iVehicles[i]->getRegNumber())
		{
			cout << "\nVehicle found and removed!\n" << endl;

			delete iVehicles[i];
			iVehicles[i] = nullptr;
		}
		iVehicles.erase(remove(iVehicles.begin(), iVehicles.end(), nullptr), iVehicles.end());
		
	}

}

void myGarage::ShowVehicleList()
{
	int nVehicles = iVehicles.size();
	if (nVehicles <= 0)
	{
		cout << "Parking is Empty" << endl;
		return;
	}
	printVehicles(iVehicles);
}

void myGarage::printVehicles(std::vector<Vehicle*> vehicles)// pass vector to print when call this function
{

	string type, name, number, color;
	int wheels, passengers;

	int i = 0;
	for (; i < vehicles.size(); i++)
	{
		type = vehicles[i]->getVehicleCategory();
		name = vehicles[i]->getVehicleName();
		number = vehicles[i]->getRegNumber();
		color = vehicles[i]->getColor();
		wheels = vehicles[i]->getNumOfWheels();
		passengers = vehicles[i]->getNumOfPassengers();

		cout << "Index: " << i + 1 << "\nType: " << type << "\nName: " << name << "\nNumber: " << number << "\nColor: " << color << "\nWheels: " << wheels << "\nPassengers: " << passengers << endl << endl;
		cout << "****************** " << endl;
	}
}

void myGarage::searchVehicleWithRegNumber()
{
	string regNum;
	cout << "Enter Registration number to Search: " << endl;
	cin >> regNum;
	std::vector<Vehicle*> vehiclesFound;// created new vector here to push back searched specific values found in loop 

	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (regNum == iVehicles[i]->getRegNumber())
		{
			vehiclesFound.push_back(iVehicles[i]);
		}
	}
	printVehicles(vehiclesFound);
}

void myGarage::searchVehicleWithColor()
{
	string Color;
	cout  << "Enter Color to Search: " << endl;
	cin >> Color;
	std::vector<Vehicle*> vehiclesFound;

	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (Color == iVehicles[i]->getColor())
		{
			vehiclesFound.push_back(iVehicles[i]);
		}
	}
	printVehicles(vehiclesFound);
}
void myGarage::searchVehicleWithWheels()
{
	int Wheels;
	cout <<  "Enter number of wheels to Search: " << endl;
	cin >> Wheels;
	std::vector<Vehicle*> vehiclesFound;

	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (Wheels == iVehicles[i]->getNumOfWheels())
		{
			vehiclesFound.push_back(iVehicles[i]);
		}
	}
	printVehicles(vehiclesFound);
}

void myGarage::searchVehicleWithPassangers()
{
	int Passangers;
	cout <<  "Enter number of Passangers to Search: " << endl;
	cin >> Passangers;
	std::vector<Vehicle*> vehiclesFound;

	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (Passangers == iVehicles[i]->getNumOfPassengers())
		{
			vehiclesFound.push_back(iVehicles[i]);
		}
	}
	printVehicles(vehiclesFound);
}

void myGarage::ShowAirQuality()
{
	int numberOfPollutingVehicles = 0;
	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (iVehicles[i]->isPollutingVehicle())
			numberOfPollutingVehicles++;
		else
			continue;
	}
	double pollution = (double)numberOfPollutingVehicles / iCapacity; // *100;
	pollution = pollution * 100;
	cout <<  "Air is " << pollution << " % polluted in the parking" << endl;
}




