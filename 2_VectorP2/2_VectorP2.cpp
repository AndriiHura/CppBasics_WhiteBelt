// 2_VectorP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
void PrintVector(const vector<int>& vec) {
	for (int n : vec) {
		cout << n << " ";
	}
	cout << endl;
}

void PrintVector1(const vector<bool>& vec) {
	int i = 1;
	for (auto n : vec) {
		cout << i << ": " << n << " ";
		++i;
	}
	cout << endl;
}

int main()
{
	//vector<int> days_in_month = { 31, 28, 31, 30, 31 };
	//if (true) {//if year is leap
	//	days_in_month[1] += 1;
	//}
	//PrintVector(days_in_month);

	vector<bool> is_holiday(28, false);
	is_holiday[22] = true;
	//PrintVector1(is_holiday);

	is_holiday.resize(31);//just adds new values
	PrintVector1(is_holiday);

	is_holiday.assign(31, false);//sets to zeros all values
	is_holiday[7] = true;
	PrintVector1(is_holiday);

	is_holiday.clear();
	cout << is_holiday.size();


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
