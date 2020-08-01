// 1_DateStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Day {
    int value;
    explicit Day(int new_value) {
        value = new_value;
    }
};

struct Month {
    int value;
    explicit Month(int new_value) {
        value = new_value;
    }
};

struct Year
{
    int value;
    explicit Year(int new_value) {
        value = new_value;
    }
};

struct Date
{
    int day;
    int month;
    int year;

    Date(Day new_day, Month new_month, Year new_year) {
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void PrintDate(const Date& dt) {
    cout << dt.day << "." << dt.month << "." << dt.year << endl;
}

int main()
{
    Date date = { Day(10), Month(11), Year{12} };

    //Date date = { {10}, {11}, {12} };

   // Date date = { 10, 11, 12 };
    PrintDate(date);
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
