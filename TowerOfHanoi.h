#pragma once
#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "input.h"

using namespace std;

class TowerOfHanoi
{
private:
	static const int MAX_PEG = 3;
	static const int MAX_RINGS = 64;
	vector<int> *peg;

	int startPeg;
	int endPeg;
	int numRings;
	int numMoves;

public:
	// Default Constructor
	TowerOfHanoi() : startPeg(0), endPeg(0), numRings(0), numMoves(0)
	{
		peg = new vector<int>[3];
	}

	// Destructor
	~TowerOfHanoi()
	{
		delete[] peg;
	}

	// Menu
	void gameMenu()
	{
		do
		{
			numRings = inputInteger("\n\tEnter the number of rings (1..64) to begin: ", 1, MAX_RINGS);
			
			// Fill the first peg with the number of rings
			for (int i = numRings; i >= 1; i--)
			{
				peg[0].push_back(i);
			}

			// Display tower
			displayTowers();
			
			// Start the game
			gameProcess(numRings, 1, 3, 2);

			// Finish the game
			cout << "\n\tThe computer has solved the game in " << numMoves << " moves.\n";
			
			// Clear vector and numMoves
			for (int i = 0; i < MAX_PEG; i++)
				peg[i].clear();
			numMoves = 0;

		} while (inputChar("\n\tPlay again? (Y-yes or N-no) ", 'Y', 'N') == 'Y');

		system("cls");
	}

	// Main Process
	void gameProcess(int n, int from_rod, int to_rod, int aux_rod) {
		if (n == 1) {
			numMoves++;
			cout << "\n\tMove #" << numMoves << ": disk 1 from peg-" << from_rod << " to peg-" << to_rod << endl;
			// Push the disk 1 to "to_rod" peg
			peg[to_rod - 1].push_back(peg[from_rod - 1].back());
			// Pop the disk 1 to "from_rod" peg
			peg[from_rod - 1].pop_back();
			displayTowers();
			return;
		}
		gameProcess(n - 1, from_rod, aux_rod, to_rod);
		numMoves++;
		cout << "\n\tMove #" << numMoves << ": disk " << n << " from peg-" << from_rod << " to peg-" << to_rod << endl;
		// Push the disk n to "to_rod" peg
		peg[to_rod - 1].push_back(peg[from_rod - 1].back());
		// Pop the disk n to "from_rod" peg
		peg[from_rod - 1].pop_back();
		displayTowers();
		gameProcess(n - 1, aux_rod, to_rod, from_rod);
	}

	// Display the three towers (1,2,3)
	void displayTowers()
	{
		cout << '\n';
		for (int i = numRings + 1; i >= 0; i--)
		{
			if (i == numRings + 1)
			{
				cout << '\t' << setw(10) << "    |    " << setw(10) << "    |    " << setw(10) << "    |    " << endl;
			}
			else if (i < 1)
			{
				cout << '\t' << setw(10) << "=========" << setw(10) << "=========" << setw(10) << "=========" << endl;
				cout << '\t' << setw(10) << "   #1    " << setw(10) << "   #2    " << setw(10) << "   #3    " << endl;
			}
			else
			{
				cout << '\t';
				for (int j = 0; j < MAX_PEG; j++)
				{
					if (peg[j].size() > 0 && i - 1 <= peg[j].size() - 1)
						cout << setw(10) << "    " + to_string(peg[j].at(i-1)) +  "    ";
					else
						cout << setw(10) << "    |    ";
				}
				cout << endl;
			}
		}
	}

};


#endif // !TOWEROFHANOI_H
