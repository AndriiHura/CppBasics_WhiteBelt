// 2_DataFormattingWhenOutputToStream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include <iomanip>

using namespace std;

void Print(const vector<string>& names, const vector<double>& values, int width) {
	for (const auto& n : names) {
		cout << setw(width) << n << ' ';
	}
	cout << endl;

	cout << fixed << setprecision(2);
	for (const auto& v : values) {
		cout << setw(width) << v << ' ';
	}
	cout << endl;
}


int main()
{
	/*vector<string> names = { "a", "b", "c" };
	vector<double> values = { 5, 0.01, 0.000005 };
	
	for (const auto& n : names) {
		cout << n << ' ';
	}
	cout << endl;

	for (const auto& v : values) {
		cout << v << ' ';
	}
	cout << endl;*/

	/*vector<string> names = { "a", "b", "c" };
	vector<double> values = { 5, 0.01, 0.000005 };

	for (const auto& n : names) {
		cout<< setw(10) << n << ' ';
	}
	cout << endl;

	cout << fixed<<setprecision(2);
	for (const auto& v : values) {
		cout<< setw(10) << v << ' ';
	}
	cout << endl;*/

	vector<string> names = { "a", "b", "c" };
	vector<double> values = { 5, 0.01, 0.000005 };
	cout << setfill('.');
	cout << left;
	Print(names, values, 15);
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
