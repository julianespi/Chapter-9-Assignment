#include <iostream>
#include <stdlib.h>
#include "input.h"

int guessGame(int guess, int limit, int guessCount, int answer, int upperLimit, int lowerLimit, int max, int min)
{
	srand(time(NULL));
	char userAnswer;
	if (guess == answer)
		return 0;
	else
	{
		guessCount++;
		if (upperLimit == 0)
		{
			if (min == 1)
			{
				answer = 1;
				guess = 1;
				cout << "Your answer must be " << answer << "." << endl;
				cout << "Your number was guessed in " << guessCount << " guess(es)." << endl;
				return guessGame(answer, limit, guessCount, answer, upperLimit, lowerLimit, max, min);
			}
			else if (max == limit)
			{
				answer = limit;
				guess = limit;
				cout << "Your answer must be " << answer << "." << endl;
				cout << "Your number was guessed in " << guessCount << " guess(es)." << endl;
				return guessGame(answer, limit, guessCount, answer, upperLimit, lowerLimit, max, min);
			}
			else
			{
				cout << "Your answer must be " << answer << "." << endl;
				cout << "Your number was guessed in " << guessCount << " guess(es)." << endl;
				return guessGame(answer, limit, guessCount, answer, upperLimit, lowerLimit, max, min);
			}
		}
		guess = rand() % upperLimit + lowerLimit;
		cout << "Is your number " << guess << "?" << endl;
		userAnswer = inputChar("Please answer with a 'y' for yes and a 'n' for no: ", 'y', 'n');
		cout << endl;
		if (userAnswer == 'y')
		{
			answer = guess;
			cout << "Your number was guessed in " << guessCount << " guess(es)." << endl;
			return guessGame(answer, limit, guessCount, answer, upperLimit, lowerLimit, max, min);
		}
		if (userAnswer == 'n')
		{
			cout << "Is your number larger than " << guess << "? (answer with a 'y' or 'n':";
			userAnswer = inputChar(" ", 'y', 'n');
			cout << endl;
			if (userAnswer == 'y')
			{
				min = guess + 1;
				lowerLimit = guess + 1;
				upperLimit = max - lowerLimit;
				return guessGame(guess, limit, guessCount, answer, upperLimit, lowerLimit, max, min);
			}
			if (userAnswer == 'n')
			{
				max = guess - 1;
				if (max < 0)
				{
					answer = guess;
					cout << "There are no other numbers to guess, play with honesty." << endl;
					cout << "Your answer must be " << answer << "." << endl;
					cout << "Your number was gussed in " << guessCount << " guess(es)." << endl;
					return guessGame(answer, limit, guessCount, answer, upperLimit, lowerLimit, max, min);
				}
				if (guess == 1)
				{
					answer = 1;
					cout << "Your answer must be " << answer << "." << endl;
					cout << "Your number was guessed in " << guessCount << " guess(es)." << endl;
					return guessGame(answer, limit, guessCount, answer, upperLimit, lowerLimit, max, min);
				}
				else
				{
					upperLimit = max - min;
					return guessGame(guess, limit, guessCount, answer, upperLimit, lowerLimit, max, min);
				}
			}
		}
	}	
}

void guess()
{
	int guessLimit = 0;
	guessLimit = rand() % 699 + 300;
	cout << "Welcome to the number guesser." << endl << "This program will guess a number from 1 to " << guessLimit << "." << endl;
	cout << "Think of a number from 1 to " << guessLimit << "." << endl << "Press any key to begin." << endl;
	cin.ignore();
	guessGame(1000, guessLimit, 0, 0, guessLimit, 1, guessLimit, 1);
}