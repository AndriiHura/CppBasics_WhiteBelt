// 1_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	//int x = 5;
	//x = 6;
	//cout << x;


	/*string s = "hello";
	string t = s;

	t += ", world!";

	cout << s << endl;
	cout << t << endl;*/

	vector<string> w = { "a", "b", "c" };
	vector<string> v;

	v = w;
	v[0] = "D";

	cout << w[0] << w[1] << endl;
	cout << v[0] << v[1] << endl;





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
