// 4_PassingFuncParamsByConstantReference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Person {
    string name;
    string surname;
    int age;
};

vector<Person> GetMoscowPopulation();//No Implementation for Function

void PrintPopulationSize(const vector<Person>& p) {
    cout << "There are " << p.size() << " people in Moscow!" << endl;
}



int main()
{
    auto start = steady_clock::now();
    vector<Person> people = GetMoscowPopulation();
    auto finish = steady_clock::now();
    cout << "GetMoscowPopulation"
        << duration_cast<milliseconds>(finish - start).count()
        << "ms" << endl;

    auto start = steady_clock::now();
    PrintPopulationSize(people);
    auto finish = steady_clock::now();
    cout << "PrintPopulationSize"
        << duration_cast<milliseconds>(finish - start).count()
        << "ms" << endl;
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
