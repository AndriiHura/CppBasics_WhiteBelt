// PA12_TimeServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <string>
#include <time.h>
using namespace std;

string AskTimeServer() {
    /* ��� ������������ ������������ ���� ���, ����������� ��������� ��������� ���� ������:
       * ���������� ������� ���������� ��������
       * ������ ���������� system_error
       * ������ ������� ���������� � ����������.
    */
    unsigned long j;
    srand((unsigned)time(NULL));

    int x =  rand() % 3;
    if (x == 0) {
        return"02:03:24";
    }
    else if (x == 1) {
        throw system_error(error_code());
    }
    else {
        throw runtime_error("Too long.");
    }
    
}

class TimeServer {
public:
    string GetCurrentTime() {
        /* ���������� ���� �����:
            * ���� AskTimeServer() ������� ��������, �������� ��� � last_fetched_time � �������
            * ���� AskTimeServer() ������� ���������� system_error, ������� ������� ��������
            ���� last_fetched_time
            * ���� AskTimeServer() ������� ������ ����������, ���������� ��� ������.
        */
        string new_time;
        try {
            new_time = AskTimeServer();
            last_fetched_time = new_time;
            return last_fetched_time;
        }
        catch (system_error& ex) {
            return last_fetched_time;
        }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // ����� ���������� ������� AskTimeServer, ���������, ��� ��� ��� �������� ���������
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
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
