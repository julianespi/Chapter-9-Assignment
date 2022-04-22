#pragma once
#pragma once
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

//Precondition: NA
//Postcondition: Displays tower of hanoi menu
void towerOfHanoi()
{

	cout << "The Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game." << endl
		<< "It consists of three pegs and a number of rings of different sizes, which can slide onto" << endl
		<< "any peg. The game starts with the rings in a neat stack in ascending order of size on one" << endl
		<< "peg, the smallest at the top, thus making a conical shape." << endl << endl
		<< "The objective of the game is to move the entire stack from the starting peg-A to ending peg-B," << endl
		<< "obeying the following simple rules:" << endl << endl
		<< "\t1. Only one disk can be moved at a time." << endl
		<< "\t2. Each move consists of taking the upper disk from one of the stacks and" << endl
		<< "\t   placing it on top of another stack or on an empty peg." << endl
		<< "\t3. No larger disk may be placed on top of a smaller disk." << endl << endl;

	vector<int> pegA;
	vector<int> pegB;
	vector<int> pegC;
	int numberOfMoves = 0;

	char doAgain;

	int numberOfdisk = inputInteger("Enter the number of disk you want to play with: ", true);

	for (int i = numberOfdisk; i > 0; i--)
	{
		pegA.push_back(i);
	}

	do
	{

		DisplayTowers(pegA, pegB, pegC, numberOfdisk);

		int option1 = inputInteger("Enter the peg you want to move a disk from(1 = A, 2 = B, 3 = C, 4 to Quit): ", 1, 4);
		if (option1 == 4)
		{
			return;
		}
		int option2 = inputInteger("Enter the peg you want to move a disk to(1 = A, 2 = B, 3 = C, 4 to Quit): ", 1, 4);
		if (option2 == 4)
		{
			return;
		}

		else if (option1 == 1 && option2 == 1)
		{
			cout << "Can not move from the same Pillar, try moving it to somehwere else..." << endl;
		}
		else if (option1 == 1 && option2 == 2)
		{
			if (pegA.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegB.size() == 0 || pegB.back() > pegA.back())
			{
				pegB.push_back(pegA.back());
				pegA.pop_back();
			}
			else if (pegB.back() < pegA.back())
				cout << "Cannot move a bigger plate over a smaller plate..." << endl;

		}
		else if (option1 == 1 && option2 == 3)
		{
			if (pegA.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegC.size() == 0 || pegC.back() > pegA.back())
			{
				pegC.push_back(pegA.back());
				pegA.pop_back();
			}
			else if (pegC.back() < pegA.back())
				cout << "Cannot move a bigger plate over a smaller plate..." << endl;

		}
		else if (option1 == 2 && option2 == 1)
		{
			if (pegB.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegA.back() > pegB.back())
			{
				pegA.push_back(pegB.back());
				pegB.pop_back();
			}
			else if (pegA.back() < pegB.back())
				cout << "Cannot move a bigger plate over a smaller plate..." << endl;

		}
		else if (option1 == 2 && option2 == 2)
		{
			cout << "Can not move from the same Pillar, try moving it to somehwere else..." << endl;
		}
		else if (option1 == 2 && option2 == 3)
		{
			if (pegB.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegC.size() == 0 || pegC.back() > pegB.back())
			{
				pegC.push_back(pegB.back());
				pegB.pop_back();
			}
			else if (pegC.back() < pegB.back())
				cout << "Cannot move a bigger plate over a smaller plate..." << endl;

		}
		else if (option1 == 3 && option2 == 1)
		{
			if (pegC.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegA.back() > pegC.back())
			{
				pegA.push_back(pegC.back());
				pegC.pop_back();
			}
			else if (pegA.back() < pegC.back())
				cout << "Cannot move a bigger plate over a smaller plate..." << endl;

		}
		else if (option1 == 3 && option2 == 2)
		{
			if (pegC.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegB.size() == 0 || pegB.back() > pegC.back())
			{
				pegB.push_back(pegC.back());
				pegC.pop_back();
			}
			else if (pegB.back() < pegC.back())
				cout << "Cannot move a bigger plate over a smaller plate..." << endl;

		}
		else if (option1 == 3 && option2 == 3)
		{
			cout << "Can not move from the same Pillar, try moving it to somehwere else..." << endl;
		}

		numberOfMoves++;

		if (checkIfComplete(pegC, numberOfdisk))
		{
			cout << endl << endl;
			cout << " YOU WON!!!" << endl;
			cout << "Number of Moves taken: " << numberOfMoves << endl;
			cout << endl << endl;

			doAgain = inputStatus("do you want to try again (y = yes and n = no):", 'Y', 'N');
			if (doAgain == 'Y')
			{
				resetTowerOfHanoi(pegA, pegC, numberOfdisk);
			}
			else break;
		}
		cout << endl;
	} while (true);
}

void towerOfHanoi()
{

}
void towerOfHanoi()
{

}
