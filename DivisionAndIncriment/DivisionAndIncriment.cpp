// DivisionAndIncriment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	/*int a = 11;
	int b = 3;*/

	/*int a = 11;
	double b = 3;

	cout << a / b;*/

	/*int x = 5;

	x += 2;
	x -= 2;
	x /= 2;
	x *= 2;*/

	int c = 5;
	
	int a = c++;
	int b = ++c;
	cout << a << b;
	cout << c;
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
