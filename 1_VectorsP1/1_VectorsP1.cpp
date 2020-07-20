// 1_VectorsP1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void PrintVector(const vector<string>& vec) {
	for (string s : vec) {
		cout << s << endl;
	}
}

void InputVector() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (string& s : v) {
		cin >> s;
		cout << "Current vector size is " << v.size()<<endl;
	}
	PrintVector(v);
}

void InputVector1() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (string s : v) {
		string x;
		cin >> x;
		s = x;
		cout << "Current vector size is " << v.size() << endl;
	}
	PrintVector(v);
}

void VectorInputter() {
	int n;
	cin >> n;
	vector<string> v;
	int i = 0;
	
	while (i < n) {
		string s;
		cin >> s;
		v.push_back(s);
		cout << "Current vector size is " << v.size() << endl;
		++i;
	}
	PrintVector(v);
}

int main()
{
	InputVector1();
	//VectorInputter();
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
