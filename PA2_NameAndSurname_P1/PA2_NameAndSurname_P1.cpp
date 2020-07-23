// PA2_NameAndSurname_P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<map>

using namespace std;

class Person {
public:
	map<string, string> FindNameByYear(int year) {
		map<string, string> FullName;
		for (auto& item : History) {
			if (item.first > year) {
				break;
			}
			else {
				if (item.second.count("first") == 0 && item.second.count("last") == 0) {
					//pass
				}
				else if (item.second.count("first") == 0) {
					FullName["last"] = item.second["last"];
				}
				else if (item.second.count("last") == 0) {
					FullName["first"] = item.second["first"];
				}
				else {
					FullName["last"] = item.second["last"];
					FullName["first"] = item.second["first"];
				}
			}
		}
		return FullName;
	}

	void ChangeFirstName(int year, const string& first_name) {
		History[year]["first"] = first_name;
	}

	void ChangeLastName(int year, const string& last_name) {
		History[year]["last"] = last_name;
	}
	string GetFullName(int year) {
		map<string, string> FullName = FindNameByYear(year);
		if (FullName.size() == 0) {
			return "Incognito";
		}
		else if (FullName.count("first") == 0) {
			return FullName["last"] + " with unknown first name";
		}
		else if (FullName.count("last") == 0) {
			return FullName["first"] + " with unknown last name";
		}
		else {
			return FullName["first"] + " " + FullName["last"] ;
		}
	}
private:
	map<int, map<string, string>> History;
};

int main()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
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
