#include<iostream>
#include "Garaget.h"
using namespace std;

int main()
{
	int garageSpace;
	cout << "Enter the space for your garage: ";
	cin >> garageSpace;

	system("CLS");
	myGarage* createGarage = new myGarage(garageSpace);
	if (createGarage)
	{
		createGarage->processChoice();
	}

	delete createGarage;

	return 0;
}