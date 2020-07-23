// PA5_NameANdSurname_P3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;


string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // изначально имя неизвестно
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
        for (int i = vs.size() - 1; i >= 0; --i) {
            if (i > 0) {
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
        if (iter >= size_v - 1) {
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
    Person(const string& name, const string& surename, int year)
    {
        year_of_birth = year;
        first_names[year] = name;
        last_names[year] = surename;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (year > year_of_birth) {
            first_names[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year > year_of_birth) {
            last_names[year] = last_name;
        }
    }

    string GetFullName(int year) const{
       if(year>=year_of_birth) {
            const string first_name = FindNameByYear(first_names, year);
            const string last_name = FindNameByYear(last_names, year);

            const vector<string> history_first_names;
            const vector<string> history_last_names;


            if (first_name.empty() && last_name.empty()) {
                return "Incognito";

                // если неизвестно только имя
            }
            else if (first_name.empty()) {
                return last_name + " with unknown first name";

                // если неизвестна только фамилия
            }
            else if (last_name.empty()) {
                return first_name + " with unknown last name";

                // если известны и имя, и фамилия
            }
            else {
                return first_name + " " + last_name;
            }
        }
       else
       {
           return"No person";
       }
    }

    string GetFullNameWithHistory(int year) const {
        if(year >= year_of_birth){
            const string first_name = FindNameByYear(first_names, year);
            const string last_name = FindNameByYear(last_names, year);

            vector<string> history_first_names_vec = GetHistoryOfNames(first_names, year);
            vector<string> history_last_names_vec = GetHistoryOfNames(last_names, year);

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

                // если неизвестно только имя
            }
            else if (first_name.empty()) {
                if (!history_last_names.empty()) {
                    return last_name + " " + history_last_names + " with unknown first name";
                }
                else {
                    return last_name + " with unknown first name";
                }

                // если неизвестна только фамилия
            }
            else if (last_name.empty()) {
                if (!history_first_names.empty())
                {
                    return first_name + " " + history_first_names + " with unknown last name";
                }
                else {
                    return first_name + " with unknown last name";
                }

                // если известны и имя, и фамилия
            }
            else {
                if (!history_first_names.empty() && !history_last_names.empty())
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
                    return first_name + " " + last_name;
                }

            }
        }
        else {
            return "No person";
        }
    }


private:
    map<int, string> first_names;
    map<int, string> last_names;
 
    int year_of_birth;
};


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
