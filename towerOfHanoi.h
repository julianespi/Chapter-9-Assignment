#pragma once
int NUMBEROFDISKS;

//Precondition: reads the winning stack + numberofdisks 
//Postcondition: checks to see if the winning stack is complete
bool checkIfComplete(vector<int> pegC, int numberOfdisk)
{
	bool isComplete = false;

	vector<int> winningStack;
	vector<int> temp = pegC;

	for (int i = numberOfdisk; i > 0; i--)
	{
		winningStack.push_back(i);
	}
	int stackSize = winningStack.size();
	if (temp.size() == winningStack.size())
	{
		for (int i = 0; i < stackSize; i++)
		{
			if (temp.back() == winningStack.back())
			{

				temp.pop_back();
				winningStack.pop_back();
				isComplete = true;
			}
			else
			{
				isComplete = false;
				break;
			}
		}
	}
	return isComplete;
}

//Precondition: NA
//Postcondition: Displays the towers of hanoi
void DisplayTowers(vector<int> pegA, vector<int> pegB, vector<int> pegC, int numberOfDisk)
{
	int devation = 0;

	for (int i = 0; i < numberOfDisk + 1; i++)
	{


		devation = numberOfDisk - pegA.size();
		if (i == 0)
			cout << setw(8) << "|" << setw(8);
		else if (devation > i)
			cout << setw(8) << "|" << setw(8);
		else if (pegA.size() != 0)
		{

			cout << setw(8) << pegA.back() << setw(8);
			pegA.pop_back();
		}
		else
		{
			cout << setw(8) << "|" << setw(8);
		}

		devation = numberOfDisk - pegB.size();
		if (i == 0)
			cout << setw(8) << "|" << setw(8);
		else if (devation > i)
			cout << setw(8) << "|" << setw(8);
		else if (pegB.size() != 0)
		{

			cout << setw(8) << pegB.back() << setw(8);
			pegB.pop_back();
		}
		else
		{
			cout << setw(8) << "|" << setw(8);
		}


		devation = numberOfDisk - pegC.size();
		if (i == 0)
			cout << setw(8) << "|" << setw(8);
		else if (devation > i)
			cout << setw(8) << "|" << setw(8);
		else if (pegC.size() != 0)
		{
			cout << setw(8) << pegC.back() << setw(8);
			pegC.pop_back();
		}
		else
		{
			cout << setw(8) << "|" << setw(8);
		}

		cout << endl;

	}
}

void solveTowerOfHanoi(int n, vector<int> &pegA,char pegAName, vector<int> &pegC, char pegCName, vector<int> &pegB, char pegBName) {
	if (n == 1) 
	{

		pegC.push_back(pegA.back());
		pegA.pop_back();
		cout << "Move disk " << n << " from peg " << pegAName << " to peg " << pegCName << endl << endl;
		DisplayTowers(pegA, pegB, pegC, NUMBEROFDISKS);
		return;
	}
	solveTowerOfHanoi(n - 1, pegA,pegAName, pegB,pegBName, pegC,pegCName);

	pegC.push_back(pegA.back());
	pegA.pop_back();
	cout << "Move disk " << n << " from peg " << pegAName << " to peg " << pegCName << endl << endl;
	DisplayTowers(pegC, pegA, pegB, NUMBEROFDISKS);
	solveTowerOfHanoi(n - 1, pegB, pegBName, pegC, pegCName, pegA, pegAName);
}

void towerOfHanoi()
{
	vector<int> pegA;
	vector<int> pegB;
	vector<int> pegC;
	int numberOfMoves = 0;

	char doAgain;

	NUMBEROFDISKS = inputInteger("Enter the number of disk you want to play with: ", true);

	for (int i = NUMBEROFDISKS; i > 0; i--)
	{
		pegA.push_back(i);
	}
	DisplayTowers(pegA, pegB, pegC, NUMBEROFDISKS);
	solveTowerOfHanoi(NUMBEROFDISKS, pegA, 'A', pegC, 'C', pegB, 'B');
	cout << endl;
}
