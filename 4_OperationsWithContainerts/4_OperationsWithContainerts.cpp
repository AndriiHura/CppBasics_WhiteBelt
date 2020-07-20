// 4_OperationsWithContainerts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
using namespace std;

int main()
{
	//ITERATING OVER CONTAINER
	string s = "abcdefg";

	for (char c : s) {
		cout << c << ", ";
	}

	vector<string> strs = { "1", "2", "3", "4", "5" };
	
	for (auto i : strs) {
		cout << i << ", ";
	}

	vector<int> nums = { 5, 3, 1, 7, 5, 6, 7, 9, 5};
	int quantity = 0;
	for (auto i : nums) {
		if (i == 5) {
			quantity += 1;
		}
	}
	cout << "\nThere are " << quantity << " fives!\n";

	//Using algorithm lib
	quantity = count(begin(nums), end(nums), 5);
	cout << "\nThere are " << quantity << " fives!\n";

	sort(begin(nums), end(nums));
	for (int n : nums) {
		cout << n;
	}

	vector<string> words = { "Hello", "My", "Dear", "Friend", "how", "are", "you", "?" };
	sort(begin(words), end(words));
	for (auto w : words) {
		cout << w << ", ";
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
