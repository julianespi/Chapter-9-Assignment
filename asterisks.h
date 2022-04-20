#pragma once
//precondition:
//postcondtion:
void pattern(int left, int length)
{
	if (length == 0)
		return;				// STOP or BASE case

	pattern(left, length / 2); // Recursive call

	cout << '\t';

	for (int i = 0; i < left; i++)
		cout << "  ";

	for (int i = 0; i < length; i++)
		cout << "* ";

	cout << '\n';

	pattern(left + length / 2, length / 2);

}

void asterisks()
{
	pattern(0, 8);
}