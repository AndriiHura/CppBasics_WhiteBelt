// PA8_StudentsList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

class Student {
private:
    string name;
    string surname;
    int day;
    int month;
    int year;

public:
    Student(string& new_name, string& new_surname, int new_day, int new_month, int new_year) {
        name = new_name;
        surname = new_surname;
        day = new_day;
        month = new_month;
        year = new_year;
    }

    
    string GetFullName() const {
        return name+' '+surname;
    }

    string GetFullDate() const {
        return to_string(day)+'.'+ to_string(month)+'.'+ to_string(year);
    }
};

int main()
{
    //ifstream input("input.txt");
    int NumberOfStudents;
    cin >> NumberOfStudents;
    vector<Student> StudentsList;

    for (int i = 0; i < NumberOfStudents; ++i) {
        string name, surname;
        cin >> name >> surname;

        int day, month, year;
        cin >> day >> month >> year;

        Student newStudent(name, surname, day, month, year);
        StudentsList.push_back(newStudent);
    }


    int NumberOfQueries;
    cin >> NumberOfQueries;

    for (int i = 0; i < NumberOfQueries; ++i) {
        string CurrentQuery;
        cin >> CurrentQuery;
        if (CurrentQuery == "name") {
            int index;
            cin >> index;
            if (index <= NumberOfStudents&&index>0)
            {
                cout << StudentsList[index - 1].GetFullName() << endl;
            }
            else {
                cout << "bad request" << endl;
            }
        }
        else if (CurrentQuery == "date") {
            int index;
            cin >> index;
            if (index <= NumberOfStudents&&index>0)
            {
                cout << StudentsList[index - 1].GetFullDate() << endl;
            }
            else {
                cout << "bad request" << endl;
            }
        }
        else {
            int index;
            cin >> index;
            cout << "bad request" << endl;
        }
    }
    return 0;
}
