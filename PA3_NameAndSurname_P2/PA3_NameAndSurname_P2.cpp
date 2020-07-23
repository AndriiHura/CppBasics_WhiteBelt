// PA2_NameAndSurname_P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;


string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // ���������� ��� ����������
    for (const auto& item : names) {
        if (item.first <= year) {
            name = item.second;
        }
        else {
            break;
        }
    }
    return name;
}

int CountChangesBeforeYear(const map<int, string>& names, int year) {
    int counter = 0;
    for (const auto& item : names) {
        if (item.first <= year) {
            ++counter;
        }
        else {
            break;
        }
    }
    return counter;
}

//string VectorToString(const vector<string>& vs) {
//    if (vs.size() != 0) {
//        string result = "(";
//        for (int i = 0; i < vs.size(); ++i) {
//            if (i < vs.size() - 1) {
//                result += vs[i] + ", ";
//            }
//            else {
//                result += vs[i] + ")";
//            }
//        }
//        return result;
//    }
//    else {
//        return "";
//    }
//}

string VectorToString(const vector<string>& vs) {
    if (vs.size() != 0) {
        string result = "(";
        for (int i = vs.size()-1; i >= 0; --i) {
            if (i >0) {
                result += vs[i] + ", ";
            }
            else {
                result += vs[i] + ")";
            }
        }
        return result;
    }
    else {
        return "";
    }
}

vector<string> GetHistoryOfNames(const map<int, string>& names, int year) {
    vector<string> history;
    int iter = 0;
    int size_v = CountChangesBeforeYear(names, year);
    for (const auto& item : names) {
        if (iter >= size_v-1) {
            break;
        }
        if (item.first <= year) {
            history.push_back(item.second);
        }
        else {
            break;
        }
        ++iter;
    }

    return history;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        const vector<string> history_first_names;
        const vector<string> history_last_names;


        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // ���� ���������� ������ ���
        }
        else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // ���� ���������� ������ �������
        }
        else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // ���� �������� � ���, � �������
        }
        else {
            return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        vector<string> history_first_names_vec = GetHistoryOfNames(first_names, year);
        vector<string> history_last_names_vec= GetHistoryOfNames(last_names, year);

        if (history_first_names_vec.size() ==
            count(begin(history_first_names_vec), end(history_first_names_vec), first_name)) 
        {
                history_first_names_vec.clear();
        }
        if (history_last_names_vec.size() ==
            count(begin(history_last_names_vec), end(history_last_names_vec), last_name))
        {
            history_last_names_vec.clear();
        }
        int f_size = history_first_names_vec.size();
        int l_size = history_last_names_vec.size();

        if (f_size - 1 >= 0)
        {
            if (history_first_names_vec[f_size - 1] == first_name) {
                history_first_names_vec.resize(f_size - 1);
            }
        }
        if (l_size - 1 >= 0)
        {
            if (history_last_names_vec[l_size - 1] == last_name) {
                history_last_names_vec.resize(l_size - 1);
            }
        }


       /* history_first_names_vec.resize(history_first_names_vec.size() - 1);
        history_last_names_vec.resize(history_last_names_vec.size() - 1);*/

        string history_first_names = VectorToString(history_first_names_vec);
        string history_last_names = VectorToString(history_last_names_vec);
        


        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // ���� ���������� ������ ���
        }
        else if (first_name.empty()) {
            if (!history_last_names.empty()) {
                return last_name + " " + history_last_names + " with unknown first name";
            }
            else {
                return last_name +" with unknown first name";
            }

            // ���� ���������� ������ �������
        }
        else if (last_name.empty()) {
            if (!history_first_names.empty())
            {
                return first_name + " " + history_first_names + " with unknown last name";
            }
            else {
                return first_name + " with unknown last name";
            }

            // ���� �������� � ���, � �������
        }
        else {
            if (!history_first_names.empty()&& !history_last_names.empty())
            {
                return first_name + " " + history_first_names + " " + last_name + " " + history_last_names;
            }
            else if (!history_first_names.empty())
            {
                return first_name + " " + history_first_names + " " + last_name;
            }
            else if (!history_last_names.empty())
            {
                return first_name + " " + last_name + " " + history_last_names;
            }
            else {
                return first_name + " " + last_name ;
            }
            
        }
    }


private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main()
{
    /*Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;*/

   /* Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;*/

   /* Person person;

    person.ChangeFirstName(2, "2_1");
    person.ChangeLastName(2, "2_2");
    person.ChangeFirstName(1, "1_1");
    person.ChangeLastName(1, "1_2");
    person.ChangeFirstName(3, "2_1");
    person.ChangeLastName(3, "2_2");
    cout << person.GetFullNameWithHistory(3) << endl;*/

    vector<string> v = { "1", "2", "3" };
    cout << v.back();
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
