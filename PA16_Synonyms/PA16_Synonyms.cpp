// PA16_Synonyms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<set>
#include <map>

using namespace std;

int main()
{
	int NumberOfQueries;
	cin >> NumberOfQueries;

	map<string ,set<string>> Synonyms;

	for (int i = 0; i < NumberOfQueries; ++i) {
		string CurrentQuery;
		cin >> CurrentQuery;

		if (CurrentQuery == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			Synonyms[word1].insert(word2);
			Synonyms[word2].insert(word1);
		}
		else if (CurrentQuery == "COUNT") {
			string word;
			cin >> word;
			if (Synonyms.count(word) != 0) {
				cout << Synonyms[word].size()<<endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (CurrentQuery == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			if (Synonyms.count(word1) == 1){
				if (Synonyms[word1].count(word2) != 0)
				{
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
			}
			else {
				cout << "NO" << endl;
			}
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
