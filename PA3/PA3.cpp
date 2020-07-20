// PA3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	double A, B, C;
	cin >> A >> B >> C;

	if (A * B * C != 0) {//IF A B and C are non zero
		double D;
		if ((B * B - 4 * A * C) < 0) {

		}
		else {
			D = sqrt(B * B - 4 * A * C);

			if (D == 0) {//D is 0
				double X1;
				X1 = (-B + D) / (2 * A);

				cout << X1;
			}
			else {
				double X1;
				X1 = (-B + D) / (2 * A);

				double X2;
				X2 = (-B - D) / (2 * A);
				cout << X1 << " " << X2;

			}
		}
	}
	else if (C*B != 0) {//If A is ZERO
		cout << -C / B;
	}
	else if (C*A != 0) {//If B is ZERO
		if (-C / A > 0)
		{
			cout << sqrt(-C / A) << " " << -sqrt(-C / A);
		}
	}
	else if(A*B != 0) {//If C is ZERO
		cout << 0 << " " << -B / A;
	}
	else if (A + C == 0 || C+B == 0) {//if A and B are ZEROs
		cout << 0;

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
