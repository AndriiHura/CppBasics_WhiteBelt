// Part3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<numeric>

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

Rational operator*(const Rational& lhs, const Rational& rhs){
    int NewNumerator = lhs.Numerator() * rhs.Numerator();
    int NewDenominator = lhs.Denominator() * rhs.Denominator();
    return Rational(NewNumerator, NewDenominator);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int NewNumerator = lhs.Numerator() * rhs.Denominator();
    int NewDenominator = lhs.Denominator() * rhs.Numerator();
    return Rational(NewNumerator, NewDenominator);
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
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
