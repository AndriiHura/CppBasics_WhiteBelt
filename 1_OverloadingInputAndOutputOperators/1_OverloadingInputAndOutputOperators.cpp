// 1_OverloadingInputAndOutputOperators.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        hour = h;
        minutes = m;
    }
};

Duration ReadDuration(istream& stream) {
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return Duration{ h, m };
}

void PrintDuration(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' << duration.minutes;
}

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

int main()
{
    /*stringstream dur_ss("10:50");
    Duration dur1 = ReadDuration(dur_ss);
    cout << dur1 << endl;*/


    //cout << "hello" << " world!";

    //operator<<(operator<<(cout, "hello"), "world");

    /*stringstream dur_ss("10:50");
    Duration dur1 = ReadDuration(dur_ss);
    cout << dur1 << endl << dur1 << endl;*/

    stringstream dur_ss("10:50");
    Duration dur1;
    dur_ss >> dur1;
    cout << dur1 << endl;

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
