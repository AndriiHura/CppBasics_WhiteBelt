// 2_DictionariesP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

void PrintMap(const map<string, int>& events) {
	cout << "Size: " << events.size() << endl;

	for (const auto& item : events) {
		cout << item.first << ": " << item.second << endl;
	}
}

void FirstExample() {
	vector<string> words = { "one", "two", "one" };

	map<string, int> counters;

	for (const string& word : words) {
		if (counters.count(word) == 0) {
			counters[word] = 1;
		}
		else {
			++counters[word];
		}
	}
	PrintMap(counters);
}

void SecondExample() {
	vector<string> words = { "one", "two", "one" };

	map<string, int> counters;

	for (const string& word : words) {
		PrintMap(counters);
		++counters[word];
	}

	PrintMap(counters);
}

int main()
{
	/*map<string, int> m = { {"one", 1}, {"two", 2}, {"three", 3} };

	m.erase("three");

	PrintMap(m);*/

	vector<string> words = { "one", "two", "three" };

	map<char, vector<string>> groupedWords;

	for (const string& word : words) {
		groupedWords[word[0]].push_back(word);
	}

	for (const auto& item : groupedWords) {
		cout << item.first << endl;
		for (const string& word : item.second)
		{
			cout << word << " ";
		}
		cout << endl;
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
