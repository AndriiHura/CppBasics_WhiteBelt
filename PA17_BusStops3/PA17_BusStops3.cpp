// PA17_BusStops3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

int main()
{
	int NumberOfQueries;
	cin >> NumberOfQueries;

	map<set<string>, int> Routes;

	for (int i = 0; i < NumberOfQueries; ++i) {
		int AmountOfStops;
		cin >> AmountOfStops;
		set<string> stops;
		for (int stp = 0; stp < AmountOfStops; ++stp) {
			string stop;
			cin >> stop;
			stops.insert(stop);
		}

		if (Routes.count(stops) == 0) {
			Routes[stops] = Routes.size()+1;
			cout << "New bus " << Routes.size() << endl;
		}
		else {
			cout << "Already exists for " << Routes[stops] << endl;
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
