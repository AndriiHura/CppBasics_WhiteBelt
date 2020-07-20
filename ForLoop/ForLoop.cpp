// ForLoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
void first() {
	vector<int> a = { 1,2,3,4,5,6,10 };

	int sum = 0;

	for (auto i : a) {
		sum += i;
	}

	cout << sum << endl;
}

void second() {
	map<string, int> b = { {"a", 1},{"b", 2},{"c", 3} };


	int sum = 0;
	string concat;
	for (auto i : b) {
		concat += i.first;
		sum += i.second;
	}

	cout << concat << endl;
	cout << sum << endl;
}

void third() {
	string a = "asdfasdfasdf";

	int i = 0;
	for (auto c : a) {
		if (c == 'a') {
			cout << i << endl;
		}
		++i;
	}
}

void forth() {
	string a = "asdfasdfasdf";

	for (int i = 0; i < a.size();++i ) {
		if (a[i] == 'a') {
			cout << i << endl;
		}
	}
}

void fifth() {
	string a = "sdafasdfasdf";

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == 'a') {
			cout << i << endl;
			break;
		}
	}
	cout << "Yes" << endl;
}

int main()
{
	//first();
	//second();
	//third();
	//forth();
	fifth();
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
