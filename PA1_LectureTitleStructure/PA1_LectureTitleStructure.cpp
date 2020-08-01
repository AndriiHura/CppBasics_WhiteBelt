// PA1_LectureTitleStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

struct Specialization
{
    string value;
    explicit Specialization(string new_value) {
        value = new_value;
    }
};

struct Course
{
    string value;
    explicit Course(string new_value) {
        value = new_value;
    }
};

struct Week
{
    string value;
    explicit Week(string new_value) {
        value = new_value;
    }
};

struct LectureTitle
{
    string specialization;
    string course;
    string week;
    
    LectureTitle(const Specialization& new_spec, const Course& new_course, const Week& new_week) {
        specialization = new_spec.value;
        course = new_course.value;
        week = new_week.value;
    }
};
int main()
{
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    ); 

    /*LectureTitle title("C++", "White belt", "4th");

    LectureTitle title(string("C++"), string("White belt"), string("4th"));

    LectureTitle title = { "C++", "White belt", "4th" };

    LectureTitle title = { {"C++"}, {"White belt"}, {"4th"} };

    LectureTitle title(
        Course("White belt"),
        Specialization("C++"),
        Week("4th")
    );

    LectureTitle title(
        Specialization("C++"),
        Week("4th"),
        Course("White belt")
    );*/

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
