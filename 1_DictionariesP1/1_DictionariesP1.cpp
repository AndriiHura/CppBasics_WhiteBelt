// 1_DictionariesP1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace std;

void PrintMap(const map<int, string>& events) {
	cout << events.size() << endl;
	for (auto item : events) {
		cout << item.first << ": " << item.second << endl;
	}
}

void PrintReversedMap(const map<string, int>& events) {
	cout << events.size() << endl;
	for (auto item : events) {
		cout << item.first << ": " << item.second << endl;
	}
}

map<string, int> BuildReversedMap(const map<int, string>& events) {
	map<string, int> result;
	
	for (auto item : events) {
		result[item.second] = item.first;
	}
	return result;
}


int main()
{
	map<int, string> events;
	events[1950] = "Bjorne Straustrup's Birth";
	events[1941] = "Dennis Richie's Birth";
	events[1970] = "UNIX epoch start";

	PrintMap(events);

	cout << events[1950] << endl;

	events.erase(1970);
	PrintMap(events);

	PrintReversedMap(BuildReversedMap(events));
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
