// 1_ConstantMethods.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	string GetSource() const{
		return source;
	}
	string GetDestination() const{
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
	}

	string source;
	string destination;
	int length;

};

void PrintRoute(const Route& route) {
	cout << route.GetSource() << "-" << route.GetDestination() << endl;
}

int main()
{

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
