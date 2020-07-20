// 3_LogicalsOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <string>
#include<map>
using namespace std;

void first() {
    int a = 3;
    int b = 5;
    if (a < b) {
        cout << "a is less than b"<<endl;
    }
}

void second()
{
    string a = "fire";
    string b = "water";
    if (a < b) {
        cout << "a is less than b"<<endl;
    }
}

void third() {
    string a = "fire";
    string b = "water";
    if (a == b) {
        cout << "a is equal to b" << endl;
    }
    else {
        cout << "a is not equal to b" << endl;
    }
}

void fourth() {
    vector<string> a = { "fire", "water" };
    vector<string> b = { "fog", "air" };
    if (a == b) {
        cout << "a is equal to b" << endl;
    }
    else {
        cout << "a is not equal to b" << endl;
    }

}

void fifth() {
    map<string, int> a;
    a["one"] = 1;
    map<string, int> b;

    if (a == b) {
        cout << "a is equal to b" << endl;
    }
    else {
        cout << "a is not equal to b" << endl;
    }

}

void sixth() {
    string s = "abc";

    if (!s.empty() && s < "zzz") {
        cout << s << endl;
    }
}

void seventh() {
    string s = "abc";
    if (!s.empty() || s < "zzz") {
        cout << s << endl;
    }
}

int main()
{
    first();
    second();
    third();
    fourth();
    fifth();
    sixth();
    seventh();
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
