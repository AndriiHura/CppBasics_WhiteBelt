// PA11_RefferenceOfCapitals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	int QueriesQuantity;
	cin >> QueriesQuantity;
	
	map<string, string> CountryToCapital;

	for (int i = 0; i < QueriesQuantity; ++i) {
		string CurrentCommand;
		cin >> CurrentCommand;

		// CHANGE COUNTRY NAME
		if (CurrentCommand == "RENAME") {
			string OldCountryName, NewCountryName;
			cin >> OldCountryName >> NewCountryName;

			if (OldCountryName == NewCountryName || //The same country name
				CountryToCapital.count(OldCountryName) == 0 || //There is no OldCountryName
				CountryToCapital.count(NewCountryName) == 1) {//NewCountryName Already Exists
				cout << "Incorrect rename, skip" << endl;
			}
			else {//If the request is correct
				string Capital = CountryToCapital[OldCountryName];
				CountryToCapital.erase(OldCountryName);
				CountryToCapital[NewCountryName] = Capital;

				cout << "Country " << OldCountryName << " with capital "
					<< Capital << " has been renamed to " << NewCountryName << endl;
			}
		}

		//CHANGE CAPITAL NAME
		else if (CurrentCommand == "CHANGE_CAPITAL") {
			string Country, NewCapital;
			cin >> Country >> NewCapital;

			//Country didn't exist before
			if (CountryToCapital.count(Country) == 0) {
				CountryToCapital[Country] = NewCapital;

				cout << " Introduce new country " << Country << " with capital "
					<< NewCapital << endl;
			}

			//If current capital of a Contry is equal to the NewCapital
			else if (CountryToCapital[Country] == NewCapital) {
				cout << "Country " << Country << " hasn't changed its capital" << endl;
			}

			//If country exists, and it has different Capital than NewCapital
			else {
				string OldCapital = CountryToCapital[Country];
				CountryToCapital[Country] = NewCapital;

				cout << "Country " << Country << " has changed its capital from "
					<< OldCapital << " to " << NewCapital << endl;
			}
		}

		//OUTPUT A CAPITAL OF A COUNTRY
		else if (CurrentCommand == "ABOUT") {
			string Country;
			cin >> Country;

			//if Country doesn't exist
			if (CountryToCapital.count(Country) == 0) {
				cout << "Country " << Country << " doesn't exist" << endl;
			}
			//If country exists
			else {
				cout << "Country " << Country << " has capital "
					<< CountryToCapital[Country] << endl;
			}
		}

		//OUTPUT CAPITALS OF ALL COUNTRIES
		else if (CurrentCommand == "DUMP") {
			//If CountryToCapital is empty
			if (CountryToCapital.size() == 0) {
				cout << "There are no countries in the world" << endl;
			}
			//if there are Countries already
			else {
				for (const auto& item : CountryToCapital) {
					cout << item.first << "/" << item.second << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
