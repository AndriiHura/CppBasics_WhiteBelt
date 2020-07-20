// DataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> //Cqn contain a sequence of chars
#include <vector> //Can contain a sequence of elements of one type.
#include <map> //Dictionary in C++
using namespace std;



//User types
struct Person {
    string name;
    string surname;
    int age;
};

int main()
{
    //Integer numbers
    int numer = 5;
    int number2 = -5;

    //Double
    double pi = 3.14;

    bool logical_value = true;

    char symbol = 'Z';

    //String
    string helloWorld = "Hello World!";
    cout << helloWorld << " - it's a string\n";

    //Vector
    vector<int> nums_vector = { 1,3,5,7 };
    cout<<"Vector size is " << nums_vector.size()<<"\n";

    //Dictionary
    map<string, int> name_to_value;
    name_to_value["one"] = 1;
    name_to_value["two"] = 2;

    cout << "two is " << name_to_value["two"]<<"\n";

   //User types example
    vector<Person> staff;
    staff.push_back({ "Ivan", "Ivanov", 25 });
    staff.push_back({ "Andrii", "Hura", 20 });

    cout << staff[0].name;

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
