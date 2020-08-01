// Part4_InputAndOutputOperators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<numeric>
#include <string>
#include <sstream>

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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
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
