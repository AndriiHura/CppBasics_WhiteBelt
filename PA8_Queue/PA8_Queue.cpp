// PA8_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void ChangeQueue(vector<bool>& queue, string Instr) {
	if (Instr == "COME") {
		int k;
		cin >> k;
		queue.resize(queue.size()+k, true);
	}
	else if (Instr == "WORRY") {//mark as worry
		int index;
		cin >> index;
		queue[index] = false;
	}
	else if (Instr == "QUIET") {//mark as quiet
		int index;
		cin >> index;
		queue[index] = true;
	}
	else if (Instr == "WORRY_COUNT") {
		int sum = 0;
		for (bool i : queue) {
			if (!i) {
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}

int main()
{
	int InstrQuant;
	cin >> InstrQuant;

	vector<bool> Queue;
	for (int i = 0; i < InstrQuant; ++i) {
		string CurrentInstr;
		cin >> CurrentInstr;
		ChangeQueue(Queue, CurrentInstr);
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
