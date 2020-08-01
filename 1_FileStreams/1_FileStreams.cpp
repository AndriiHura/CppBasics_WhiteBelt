// 1_FileStreams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>

using namespace std;

void ReadAll(const string& path) {
    ifstream input(path);
    if (input) {
        string line;
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
}

int main()
{
    /*ifstream input("Hello.txt");
    string line;
   /* getline(input, line);
    cout << line << endl;

    getline(input, line);
    cout << line << endl;

    getline(input, line);
    cout << line << endl;*/

    /*ifstream input("Hello.txt");
    string line;
    if (input.is_open()) {
        while (getline(input, line)) {
            cout << line << endl;
        }
        cout << "Done!" << endl;

    } 
    else {
        cout << "Wrong file!" << endl;
    }*/

   /* ifstream input("date.txt");
    string year;
    string month;
    string day;

    if (input.is_open()) {
        getline(input, year, '-');
        getline(input, month, '-');
        getline(input, day, '-');
    }
    cout << year << '-' << month << '-' << day << endl;*/

  /*  ifstream input("date.txt");
    int year = 0;
    int month = 0;
    int day = 0;

    if (input) {
        input >> year;
        input.ignore(1);
        input >> month;
        input.ignore(1);
        input >> day;
    }

    cout << year << '-' << month << '-' << day << endl;*/

    const string path = "output.txt";

    ofstream output(path, ios::app);
    output << ", world!" << endl;

    ReadAll(path);
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
