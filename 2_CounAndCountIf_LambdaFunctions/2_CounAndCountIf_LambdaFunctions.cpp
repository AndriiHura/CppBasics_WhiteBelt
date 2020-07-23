// 2_CounAndCountIf_LambdaFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void PrintVector(const vector<int>& v, const string& title) {
	cout << title << ": ";
	for (const int& s : v) {
		cout << s << " ";
	}
	cout << endl;
}

bool Gt2(int x) {
	if (x > 2) {
		return true;
	}
	return false;
}

bool Lt2(int x) {
	if (x < 2) {
		return true;
	}
	return false;
}

int main()
{
	vector<int> n = { 1,3,2,5,4 };
	
	/*int cnt = 0;
	for (const auto& i : n) {
		if (i == 2) {
			++cnt;
		}
	}
	cout << cnt;*/

	/*cout << count(begin(n), end(n), 2) << endl;*/

	/*cout << count_if(begin(n), end(n), Gt2)<<endl;
	cout << count_if(begin(n), end(n), Lt2);*/

	/*cout << count_if(begin(n), end(n), [](int i) {
		if (i > 2) {
			return true;
		}
		return false;
		}) << endl;*/

	int thr = 0;
	cin >> thr;

	cout << count_if(begin(n), end(n), [thr](int i) {
		if (i > thr) {
			return true;
		}
		return false;
		}) << endl;
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
