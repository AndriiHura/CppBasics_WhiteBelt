// PA12_BusStops1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int NumberOfRequests;
	cin >> NumberOfRequests;

	map<string, vector<string>> BusToStops;
	map<string, vector<string>> StopToBus;

	for (int i = 0; i < NumberOfRequests; ++i) {
		string Command;
		cin >> Command;

		if (Command == "NEW_BUS") {
			string BusId;
			cin >> BusId;

			BusToStops[BusId];

			int NumberOfStops;
			cin >> NumberOfStops;


			for (int stop = 0; stop < NumberOfStops; ++stop) {
				string StopName;
				cin >> StopName;

				StopToBus[StopName].push_back(BusId);
				BusToStops[BusId].push_back(StopName);
			}

		}

		else if (Command == "BUSES_FOR_STOP") {
			string StopName;
			cin >> StopName;

			if (StopToBus[StopName].size() == 0) {
				cout << "No stop" << endl;
			}
			else {
				for (const string& bus : StopToBus[StopName])
				{
					cout << bus << " ";
				}
				cout << endl;
			}
		}

		else if (Command == "STOPS_FOR_BUS") {
			string BusId;
			cin >> BusId;

			if (BusToStops.count(BusId) == 0) {//If there is no such BusId at all
				cout << "No bus" << endl;
			}


			else//There is such BusId
			{
				for (const string& stp : BusToStops[BusId]) {
					cout << "Stop " << stp << ": ";

					if (StopToBus[stp].size() <= 1) {//If it is only bus on a stop
						cout << "no interchange" << endl;
					}
					
					else //If there are other buses
					{
						for (const string& bus : StopToBus[stp]) {
							if (bus != BusId)
							{
								cout << bus << " ";
							}
						}
						cout << endl;
					}
				}
			}

		}

		else if (Command == "ALL_BUSES") {
			if (BusToStops.size() == 0) {
				cout << "No buses" << endl;
			}
			else {
				for (const auto& item : BusToStops) {
					cout << "Bus " << item.first << ": ";
					for (const string& stp : item.second) {
						cout << stp << " ";
					}
					cout << endl;
				}
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
