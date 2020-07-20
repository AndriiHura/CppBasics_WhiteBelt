// PA7_AverageTemperature.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> DayTemperatureInput() {
    int DaysNumber;
    cin >> DaysNumber;

    vector<int> TemperatureEachDay(DaysNumber);

    for (int& d : TemperatureEachDay) {
        cin >> d;
    }
    return TemperatureEachDay;
}

int GetAverageSum(const vector<int>& vec) {
    int TempSum = 0;
    for (auto d : vec) {
        TempSum += d;
    }
    int AverageTemp = TempSum / vec.size();
    
    return AverageTemp;
}

void PrintVector(const vector<int>& vec) {
    cout << vec.size() << endl;
    for (auto n : vec) {
        cout << n << " ";
    }
}

vector<int> GetResultVector(const vector<int>& vec) {
    vector<int> ResultDays;

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > GetAverageSum(vec)) {
            ResultDays.push_back(i);
        }
    }

    return ResultDays;
}

int main()
{
    vector<int> Temperatures = DayTemperatureInput();
    
    vector<int> ResultDays = GetResultVector(Temperatures);

    PrintVector(ResultDays);

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
