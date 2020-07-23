// 1_MinMaxSortFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <vector>	
#include<algorithm>

using namespace std;

int Min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

void PrintVector(const vector<int>& v, const string& title) {
	cout << title << ": ";
	for (const int& s : v) {
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	/*cout << Min(2, 3) << endl;
	cout << Max(2, 3) << endl;*/

	/*cout << min(2, 3) << endl;
	cout << max(2, 3) << endl;*/

	/*string s1 = "abc";
	string s2 = "bca";

	cout << min(s1, s2) << endl;
	cout << max(s1, s2) << endl;*/

	vector<int> n = { 1,3,2,5,4 };
	
	PrintVector(n, "Init");

	sort(begin(n), end(n));

	PrintVector(n, "Sorted");
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
