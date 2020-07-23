// 3_LifeTimelineOfObject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ComputeDistance(const string& source, const string& destination) {
	return source.length() - destination.length();
}

class Route {
public:
	Route() {
		source = "Moscow";
		destination = "Saint Petersburg";
		UpdateLength();
		cout << "Default constructed" << endl;
	}
	Route(const string& new_source, const string& new_dest) {
		source = new_source;
		destination = new_dest;
		UpdateLength();
		cout << "Constructed" << endl;
	}

	~Route() {
		cout << "Destructed" << endl;
	}

	string GetSource() const {
		return source;
	}
	string GetDestination() const {
		return destination;
	}
	int GetLength() const {
		return length;
	}
	void SetSource(const string& new_source) {
		source = new_source;
		UpdateLength();
	}
	void SetDestination(const string& new_destination) {
		destination = new_destination;
		UpdateLength();
	}
private:
	void UpdateLength() {
		length = ComputeDistance(source, destination);
		ComputeDistanceLog.push_back(
			source + " " + destination);
	}

	string source;
	string destination;
	int length;

	vector<string> ComputeDistanceLog;
};

void PrintRoute(const Route& route) {
	cout << route.GetSource() << "-" << route.GetDestination() << endl;
}

void Worthless(Route route) {
	cout << 2 << endl;
}

Route GetRoute() {
	cout << 1 << endl;
	return {};
}

int main()
{
	/*cout << 1 << endl;
	Route route;
	cout << 2 << endl;*/

	/*for (int i : {0, 1}) {
		cout << "Step " << i << ": " << 1 << endl;
		Route route;
		cout << "Step " << i << ": " << 2 << endl;
	}
	cout << "End" << endl;

	return 0;*/

	/*cout << 1 << endl;
	Route first_route;
	if (false) {
		cout << 2 << endl;
		return 0;
	}
	cout << 3 << endl;
	Route second_route;
	cout << 4 << endl;*/

	/*cout << 1 << endl;
	Worthless({});
	cout << 3 << endl;*/

	/*Route route = GetRoute();
	cout << 2 << endl;*/

	GetRoute();
	cout << 2 << endl;

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
