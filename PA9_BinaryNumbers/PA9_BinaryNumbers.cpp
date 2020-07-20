// PA9_BinaryNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int Number;
	cin >> Number;
	
	vector<int> concat;

	if (Number > 0)
	{
		while (true) {
			if (Number == 1) {
				concat.push_back(1);
				break;
			}
			if (Number % 2 == 0) {
				concat.push_back(0);
			}
			else {
				concat.push_back(1);
			}
			Number /= 2;
		}

		
		for (int i = concat.size()-1; i >= 0; --i) {
			cout << concat[i];
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
