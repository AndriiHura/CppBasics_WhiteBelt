// PA7_ReadingAndOutputtingTheTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>

using namespace std;

int main()
{
	int rows, cols;
	ifstream input("input.txt");
	input >> rows >> cols;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int num;
			input >> num;
			if (j < cols - 1) {
				cout<< setw(10) << num << ' ';
				input.ignore(1);
			}
			else {
				cout<< setw(10) << num;
			}
		}
		if (i < rows - 1)
		{
			cout << endl;
		}
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
