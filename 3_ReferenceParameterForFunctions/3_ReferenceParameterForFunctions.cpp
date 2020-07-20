// 3_ReferenceParameterForFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include<vector>
#include<string>

using namespace std;

void Swap(int& x, int& y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}

vector<int> Sort(vector<int> v) {
	sort(begin(v), end(v));
	return v;
}

void Sort1(vector<int>& v) {
	sort(begin(v), end(v));
}

int main()
{
	int a = 1;
	int b = 2;
	Swap(a, b);
	cout << "a == " << a << endl;
	cout << "b == " << b << endl;

	vector<int> nums = { 3, 6,1,2,0,2 };
	//sort(begin(nums), end(nums));

	//nums = Sort(nums);
	Sort1(nums);

	for (auto  n : nums) {
		cout << n << " ";
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
