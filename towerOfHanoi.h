#pragma once
int numberOfdisk;

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
	/*cout << setw(8) << "PegA" << setw(8) << setw(8) << "PegB" << setw(8) << setw(8) << "PegC" << setw(8) << endl;*/
	cout << endl;
}

//Precondition:user input of how many disks 
//Postcondition: sets the number of disks to play with
void resetTowerOfHanoi(vector<int>& pegA, vector<int>& pegC, int& numberOfdisk)
{
	int size = pegC.size();
	for (int i = 0; i < size; i++)
		pegC.pop_back();

	numberOfdisk = inputInteger("Enter the number of disk you want to play with: ", true);

	for (int i = numberOfdisk; i > 0; i--)
	{
		pegA.push_back(i);
	}

}

void solveTowerOfHanoi(int n, vector<int> &pegA, vector<int> &pegC, vector<int> &pegB) {
	if (n == 1) {
		pegC.push_back(pegA.back());
		pegA.pop_back();
		DisplayTowers(pegA, pegB, pegC, numberOfdisk);
		return;
	}
	solveTowerOfHanoi(n - 1, pegA, pegB, pegC);
	pegC.push_back(pegA.back());
	pegA.pop_back();
	DisplayTowers(pegC, pegA, pegB, numberOfdisk);
	solveTowerOfHanoi(n - 1, pegB, pegC, pegA);
}

void towerOfHanoi()
{

	vector<int> pegA;
	vector<int> pegB;
	vector<int> pegC;
	int numberOfMoves = 0;

	char doAgain;

	numberOfdisk = inputInteger("Enter the number of disk you want to play with: ", true);

	for (int i = numberOfdisk; i > 0; i--)
	{
		pegA.push_back(i);
	}

	solveTowerOfHanoi(numberOfdisk, pegA, pegC, pegB);
}
