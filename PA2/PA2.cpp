// PA2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S1, S2, S3;

	cin >> S1 >> S2 >> S3;
	if (S1 <= S2 && S1 <= S3) {
		cout << S1;
	}
	else if (S2 <= S1 && S2 <= S3) {
		cout << S2;
	}
	else if (S3 <= S1 && S3 <= S2) {
		cout << S3;
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
