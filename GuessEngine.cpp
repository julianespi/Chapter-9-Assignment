#include <iostream>
#include <stdlib.h>
#include "input.h"

//precondition: none
//postcondition: runs a number guessing game
int guessGame(int guess, int limit, int guessCount, int answer)
{
	srand(time(0));
	char userAnswer;
	int upperLimit = 0;
	int lowerLimit = 1;
	upperLimit = limit;
	if (guess == answer)
		return 0;
	else
	{
		guessCount++;
		guess = rand() % upperLimit + lowerLimit;
		cout << "Is your number " << guess << "?" << endl;
		userAnswer = inputChar("Please answer with a 'y' for yes and a 'n' for no: ", 'y', 'n');
		cout << endl;
		if (userAnswer == 'y')
		{
			answer = guess;
			cout << "Your number was guessed in " << guessCount << " guess(es)." << endl;
			return guessGame(answer, limit, guessCount, answer);
		}
		if (userAnswer == 'n')
		{
			cout << "Is your number larger than " << guess << "? (answer with a 'y' or 'n':";
			userAnswer = inputChar(" ", 'y', 'n');
			cout << endl;
			if (userAnswer == 'y')
			{
				if (guess == limit)
				{
					answer = limit;
					cout << "Your answer must be " << answer << "." << endl;
					return guessGame(answer, limit, guessCount, answer);
				}
				else
				{
					lowerLimit = guess + 1;
					return guessGame(guess, limit, guessCount, answer);
				}
			}
			if (userAnswer == 'n')
			{
				if (guess == 1)
				{
					answer = 1;
					cout << "Your answer must be " << answer << "." << endl;
					return guessGame(answer, limit, guessCount, answer);
				}
				else
				{
					upperLimit = guess - 1;
					return guessGame(guess, limit, guessCount, answer);
				}
			}
		}
	}	
}

//precondition: none
//postcondition: sets up a number guessing game
void guess()
{
	int guessLimit = 0;
	guessLimit = rand() % 699 + 300;
	cout << "Welcome to the number guesser." << endl << "This program will guess a number from 1 to " << guessLimit << "." << endl;
	cout << "Think of a number from 1 to " << guessLimit << "." << endl << "Press any key to begin." << endl;
	cin.ignore();
	guessGame(1000, guessLimit, 0, 0);
}
