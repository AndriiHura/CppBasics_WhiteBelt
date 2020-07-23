// 2_InitializationOfVariables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

//void PrintInt() {
//	int x;
//	cout << x << endl;
//}
//
//void PrintDouble() {
//	double pi = 3.14;
//	cout << pi << endl;
//}

void PrintParity(int x) {
	string parity = x % 2 == 0 ? "even" : "odd";
	cout << x << " is " << parity << endl;
}

string GetPositivity(int x) {
	if (x > 0) {
		return "Positive";
	}
	else if (x < 0) {
		return "Negative";
	}
	else {
		return "zero";
	}
}

string GetPositivity1(int x) {
	return x > 0 ? "positive"
		: (x == 0 ? "zero" : "negative");
}

void PrintPositivity(int x) {
	string positivity = GetPositivity1(x);
	
	cout << x << " is " << positivity << endl;
}

int main()
{
	PrintPositivity(2);
	PrintPositivity(0);
	PrintPositivity(-5);
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
