/*
Kevin Lehman  - 1463553
Tarrant County College - COSC 1437- Fall 2017
Assignment 1 - Week 8
*/

#include<iostream>
#include<fstream>
using namespace std;

const int NAME_SIZE = 20;
const int STREET_SIZE = 30;
const int CITY_SIZE = 20;
const int STATE_CODE_SIZE = 3;

struct Customers 
{
	long customerNumber;
	char name[NAME_SIZE];
	char streetAddress_1[STREET_SIZE];
	char streetAddress_2[STREET_SIZE];
	char city[CITY_SIZE];
	char state[STATE_CODE_SIZE];
	int zipCode;
	char isDeleted;
	char newLine;
};

int main()
{
	Customers newCust;
	char loop = 'n';
	int count = 0;

	fstream customer("customer.dat", ios::out | ios::binary);

	do
	{
		
		newCust.customerNumber = count;
		cout << "Enter new customers name:" << endl;
		cin.getline(newCust.name, NAME_SIZE);
		cout << "Enter new customers address line 1:" << endl;
		cin.getline(newCust.streetAddress_1, STREET_SIZE);
		cout << "Enter new customers address line 2:" << endl;
		cin.getline(newCust.streetAddress_2, STREET_SIZE);
		cout << "Enter new customers city" << endl;
		cin.getline(newCust.city, CITY_SIZE);
		cout << "Enter new customers state code:" << endl;
		cin.getline(newCust.state, STATE_CODE_SIZE);
		cout << "Enter new customers zip code:" << endl;
		cin >> newCust.zipCode;
		cin.ignore();

		newCust.isDeleted = 'N';
		newCust.newLine = '\n';
		customer.write(reinterpret_cast<char *>(&newCust), sizeof(newCust));

		cout << "Would you like to add another new customer? Y for yes and N for no" << endl;
		cin >> loop;
		cin.ignore();
		count++;
	} while (loop == 'Y' || loop == 'y');

	customer.close();
	system("PAUSE");
	return 0;
}