// 1_IntroductionToExceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <exception>

using namespace std;
struct Date {
    int year;
    int month;
    int day;
};

void EnsureNextSymbolAndSkip(stringstream& stream) {
    if (stream.peek() != '/') {
        stringstream ss;
        ss << "expected / , but has: " << char(stream.peek());
        throw runtime_error(ss.str());
    }
}

Date ParseDate(const string& s) {
    stringstream stream(s);
    Date date;
    stream >> date.year;
    EnsureNextSymbolAndSkip(stream);
    stream.ignore(1);
    stream >> date.month;
    EnsureNextSymbolAndSkip(stream);
    stream.ignore(1);
    stream >> date.day;
    return date;
}



int main()
{
    string date_str = "2017f01d25";
    try {
        Date date = ParseDate(date_str);
        cout << setw(2) << setfill('0') << date.day << '.'
            << setw(2) << setfill('0') << date.month << '.'
            << date.year << endl;
    }
    catch(const exception& ex){
        cout << "exception happens "<<ex.what();
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
