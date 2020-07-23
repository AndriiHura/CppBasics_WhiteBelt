// PA2_SortingStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>    
#include <vector>
#include <algorithm>

using namespace std;

void PrintVector(const vector<string>& v) {
	for (const string& s : v) {
		cout << s << " ";
	}
	cout << endl;
}

void StringToLower(string& s1) {
	for (auto& c : s1) {
		c = tolower(c);
	}
}

int main()
{
	int NumberOfLetters;
	cin >> NumberOfLetters;
	vector<string> vec(NumberOfLetters);
	for (string& s : vec) {
		cin >> s;
	}

	sort(begin(vec), end(vec), [](string s1, string s2) {
		StringToLower(s1);
		StringToLower(s2);
		if (s1 < s2) {
			return true;
		}
		return false;
		});
	PrintVector(vec);
	

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
