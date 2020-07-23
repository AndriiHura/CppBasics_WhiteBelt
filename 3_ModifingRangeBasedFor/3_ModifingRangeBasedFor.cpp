// 3_ModifingRangeBasedFor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void PrintVector(const vector<int>& v, const string& title) {
	cout << title << ": ";
	for (const int& s : v) {
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> n = { 1,3,2,5,4 };
	PrintVector(n, "Init");

	/*for (int i = 0; i< n.size(); ++i) {
		++n[i];
	}*/

	for (auto& i : n) {
		++i;
	}

	PrintVector(n, "Inc ");

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
