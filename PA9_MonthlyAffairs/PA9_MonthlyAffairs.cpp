// PA9_MonthlyAffairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void PrintVector(const vector<string>& affairs) {
	cout << affairs.size() << " ";
	for (auto affair : affairs) {
		cout << affair << " ";
	}
	cout << endl;
}

int main()
{
	int InstrQuant;
	cin >> InstrQuant;

	vector<int> DaysInMonths = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int MonthIndex = 0;

	vector<vector<string>> AffairList(DaysInMonths[MonthIndex]);


	for (int i = 0; i < InstrQuant; ++i) {
		string Instraction;
		cin >> Instraction;
		


		if (Instraction == "ADD") {//Adding new affairs to a particular day
			int index;
			cin >> index;//Index of a day;
			--index;

			string Affair;//Name of affair;
			cin >> Affair;

			AffairList[index].push_back(Affair);
		}
		else if (Instraction == "DUMP")
		{
			int index;
			cin >> index;//Index of a day;
			--index;

			PrintVector(AffairList[index]);
		}
		else if (Instraction == "NEXT") {//Changing to the next mont
			int OldMonthSize = DaysInMonths[MonthIndex];

			MonthIndex += 1;
			MonthIndex %= 12;

			int NewMonthSize = DaysInMonths[MonthIndex];

			if (OldMonthSize == NewMonthSize) {
				//If next month is of the same size
				//We leave vector the same
			}
			else if (NewMonthSize > OldMonthSize)
			{	//If next month is bigger than previous
				//We just add free cells
				AffairList.resize(NewMonthSize);
			}
			else if (NewMonthSize < OldMonthSize) {
				//If next month is less than previous
				//We create smaller list, and to the last cell we add all the rest
				vector<vector<string>> tmp = AffairList;
				tmp.resize(NewMonthSize);

				for (int i = OldMonthSize - 1; i >= NewMonthSize; --i) {
					tmp[NewMonthSize - 1].insert(end(tmp[NewMonthSize - 1]), begin(AffairList[i]), end(AffairList[i]));
				}
				AffairList = tmp;

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
