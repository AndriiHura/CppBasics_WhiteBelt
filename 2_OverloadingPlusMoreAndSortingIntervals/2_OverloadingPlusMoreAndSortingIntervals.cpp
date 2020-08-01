// 2_OverloadingPlusMoreAndSortingIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int minutes;

    Duration(int h = 0, int m = 0) {
        int total = h * 60 + m;
        hour = total/60;
        minutes = total%60;
    }
};

ostream& operator <<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' << duration.minutes;
    return stream;
}

istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.minutes;
    return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs) {
    return Duration{ lhs.hour + rhs.hour, lhs.minutes + rhs.minutes };
}

void PrintVector(const vector<Duration>& durs) {
    for (const Duration& dur : durs) {
        cout << dur << " ";
    }
    cout << endl;
}

bool operator<(const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) {
        return lhs.minutes < rhs.minutes;
    }
    return lhs.hour < rhs.hour;
}

int main()
{
    stringstream dur_ss("02:88");
    Duration dur1;
    dur_ss >> dur1;

    Duration dur2 = { 0, 35 };
    Duration dur3 = dur1 + dur2;
    /*cout << dur1 << endl;
    cout << dur1 + dur2 << endl;*/

    vector<Duration> v = { dur3 , dur1, dur2 };

    PrintVector(v);

    sort(begin(v), end(v));

    PrintVector(v);


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
