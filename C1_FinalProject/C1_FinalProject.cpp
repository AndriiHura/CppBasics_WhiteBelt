// C1_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<map>
#include<set>
#include <vector>
#include<algorithm>
#include <iomanip>
#include<sstream>

using namespace std;

class Date {
public:


    Date(int NewYear, int NewMonth, int NewDay) {
        Year = NewYear;

        if (NewMonth > 12 || NewMonth < 1) {
            throw invalid_argument("Month value is invalid: "+ to_string(NewMonth));
        }
        Month = NewMonth;

        if (NewDay > 31 || NewDay < 1) {
            throw invalid_argument("Day value is invalid: " + to_string(NewDay));
        }
        Day = NewDay;
    }
    Date() {

    }

    int GetYear() const {
        return Year;
    }
    int GetMonth() const {
        return Month;
    }
    int GetDay() const {
        return Day;
    }
private:
    int Day;
    int Month;
    int Year;
};


bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    else {
        if (lhs.GetMonth() != rhs.GetMonth()) {
            return lhs.GetMonth() < rhs.GetMonth();
        }
        else {
            return lhs.GetDay() < rhs.GetDay();
        }
    }
}

void PrintSet(const set<string>& st) {
    vector<string> SortedEvents(st.begin(), st.end());
    sort(begin(SortedEvents), end(SortedEvents));
    int size = SortedEvents.size();
    for (const string& s : SortedEvents) {
        cout << s;
            cout << endl;
    }
}

void PrintDate(const Date& date) {
    cout << setfill('0');
    cout << setw(4) << date.GetYear() << '-';
    cout << setw(2) << date.GetMonth() << '-';
    cout << setw(2) << date.GetDay()<<" ";
}

void PrintHelper(const set<string>& st, const Date& date) {
    vector<string> SortedEvents(st.begin(), st.end());
    sort(begin(SortedEvents), end(SortedEvents));
    int size = SortedEvents.size();
    for (const string& s : SortedEvents) {
        PrintDate(date);
        cout << s;
        cout << endl;
    }
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        DateToEvents[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (DateToEvents.count(date) == 1) {//There is such date
            if (DateToEvents[date].count(event) == 1) {//there is such event
                DateToEvents[date].erase(event);
                if (DateToEvents[date].size() == 0) {
                    DateToEvents.erase(date);
                }
                cout << "Deleted successfully" << endl;
                return true;
            }
            else {//there is no such event
                cout << "Event not found" << endl;
                return false;
            }
        }
        else{//There are no such date yet
            cout << "Event not found" << endl;
            return false;
        }

    }

    int  DeleteDate(const Date& date) {
        if (DateToEvents.count(date) == 1) {//There is such date
            int NumberOfDeletedEvents = DateToEvents[date].size();
            cout << "Deleted " << NumberOfDeletedEvents << " events"<<endl;
            DateToEvents.erase(date);
            return NumberOfDeletedEvents;
        }
        else {//There are no such date yet
            cout << "Deleted 0 events" << endl;
            return 0;
        }
    }

    set<string> Find(const Date& date) const {
        if (DateToEvents.count(date) == 1) {
            PrintSet(DateToEvents.at(date));
            return DateToEvents.at(date);
        }
        else {
            return {};
        }
    }

    void Print() const {
        if (DateToEvents.size() != 0)
        {
            for (const auto& item : DateToEvents) {
                PrintHelper(item.second, item.first);
            }
        }
    }

private:
    map<Date, set<string>> DateToEvents;
};

bool ReadDataAdd(stringstream& ss, Database& db) {
    int y, m, d;
    char ch1, ch2;
    string event;
    ss >> y >> ch1 >> m >> ch2 >> d;
    ss.ignore(1);
    ss>> event;
    if (ss&&ch1=='-'&&ch2=='-') {
        Date date(y, m, d);
        db.AddEvent(date, event);
        return true;
    }
    else {
        stringstream SSer(ss.str());
        string error;
        SSer >> error >> error;
        cout << "Wrong date format: "<<error;
        return false;
    }
}

Date ReadData(stringstream& ss) {
    int y, m, d;
    char ch1, ch2;
    ss >> y >> ch1 >> m >> ch2 >> d;
    if (ss && ch1 == '-' && ch2 == '-'&&(ss.peek()==EOF|| ss.peek() == ' ')) {
        Date date(y, m, d);
        return date;
    }
    else {
        stringstream SSer(ss.str());
        string error;
        SSer >> error >> error;
        cout << "Wrong date format: " << error;
        exit(0);
    }
}


int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        stringstream ss(command);

        string operation;
        ss >> operation;

        if (operation == "Add") {
            try
            {
                Date date = ReadData(ss);
                string event;
                ss >> event;
                db.AddEvent(date, event);
                

            }
            catch (invalid_argument& ex) {
                cout << ex.what();
                return 0;
            }
        }
        else if (operation == "Print") {
            db.Print();
        }
        else if (operation == "Find") {
            try
            {
                Date date = ReadData(ss);
                db.Find(date);
            }
            catch (invalid_argument& ex) {
                cout << ex.what();
                return 0;
            }
        }
        else if (operation == "Del") {
            try
            {
                Date date = ReadData(ss);
                string event;
                ss >> event;
                if (ss)
                {
                    db.DeleteEvent(date, event);
                }
                else {
                    db.DeleteDate(date);
                }
            }
            catch (invalid_argument& ex) {
                cout << ex.what();
                return 0;
            }
        }
        else  {
            if (operation.length() >= 1)
            {
                cout << "Unknown command: " << operation << endl;

            }
        }
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
