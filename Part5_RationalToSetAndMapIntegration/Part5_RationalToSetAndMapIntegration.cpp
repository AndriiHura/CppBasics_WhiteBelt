// Part5_RationalToSetAndMapIntegration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<numeric>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include<vector>

using namespace std;

class Rational {
public:
    void CheckSigns() {
        if (numerator < 0 && denominator < 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        else if (numerator > 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator != 0 && denominator != 0)
        {
            int reducing = gcd(numerator, denominator);
            this->numerator = numerator / reducing;
            this->denominator = denominator / reducing;
            CheckSigns();
        }
        else {
            this->denominator = 1;
            this->numerator = 0;
        }

    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int NewNumerator = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    int NewDenominator = lhs.Denominator() * rhs.Denominator();
    return Rational(NewNumerator, NewDenominator);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int NewNumerator = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    int NewDenominator = lhs.Denominator() * rhs.Denominator();
    return Rational(NewNumerator, NewDenominator);
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int NewNumerator = lhs.Numerator() * rhs.Numerator();
    int NewDenominator = lhs.Denominator() * rhs.Denominator();
    return Rational(NewNumerator, NewDenominator);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int NewNumerator = lhs.Numerator() * rhs.Denominator();
    int NewDenominator = lhs.Denominator() * rhs.Numerator();
    return Rational(NewNumerator, NewDenominator);
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    if (stream) {
        int NewNumerator, NewDenominator;
        stream >> NewNumerator;
        stream.ignore(1);
        if (stream)
        {
            stream >> NewDenominator;
            Rational tmp(NewNumerator, NewDenominator);
            rational = tmp;
        }
    }
    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator()*rhs.Denominator() < rhs.Numerator()* lhs.Denominator());
}

int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
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
