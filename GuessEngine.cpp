#include <iostream>
#include <stdlib.h>
#include "input.h"

int guessGame(int guess, int limit, int guessCount, int answer, int upperLimit, int lowerLimit)
{
	srand(time(0));
	char userAnswer;
	if (guess == answer)
		return 0;
	else
	{
		guessCount++;
		if (guess == limit)
		{
			answer = limit;
			cout << "Your answer must be " << answer << "." << endl;
			cout << "Your number was guessed in " << guessCount << " guess(es)." << endl;
			return guessGame(answer, limit, guessCount, answer, upperLimit, lowerLimit);
		}
		if (guess == 1)
		{
			answer = 1;
			cout << "Your answer must be " << answer << "." << endl;
			cout << "Your number was guessed in " << guessCount << " guess(es)." << endl;
			return guessGame(answer, limit, guessCount, answer, upperLimit, lowerLimit);
		}
		guess = rand() % upperLimit + lowerLimit;
		cout << "Is your number " << guess << "?" << endl;
		userAnswer = inputChar("Please answer with a 'y' for yes and a 'n' for no: ", 'y', 'n');
		cout << endl;
		if (userAnswer == 'y')
		{
			answer = guess;
			cout << "Your number was guessed in " << guessCount << " guess(es)." << endl;
			return guessGame(answer, limit, guessCount, answer, upperLimit, lowerLimit);
		}
		if (userAnswer == 'n')
		{
			cout << "Is your number larger than " << guess << "? (answer with a 'y' or 'n':";
			userAnswer = inputChar(" ", 'y', 'n');
			cout << endl;
			if (userAnswer == 'y')
			{
					lowerLimit = guess + 1;
					return guessGame(guess, limit, guessCount, answer, upperLimit, lowerLimit);
			}
			if (userAnswer == 'n')
			{
					upperLimit = guess - 1;
					return guessGame(guess, limit, guessCount, answer, upperLimit, lowerLimit);
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
	guessGame(1000, guessLimit, 0, 0, guessLimit, 1);
}