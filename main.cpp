// Names of Group:
// Julian Espinoza
// Wesley Goo
// Hamza Patel
// Arturo Islas Mejia
// Date: 2/16/2022

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "input.h"
#include "asterisks.h"
#include "nQueens.h"
#include "numberGuess.h"
#include "towerOfHanoi.h"
using namespace std;

int mainMenuOption();
int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(1); break;
        case 1: asterisks(); break;
        case 2: towerOfHanoi(); break;
        case 3: nQueens(); break;
        case 4:nQueens(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

//Precondition:none
//PostCondition:displays the main menu
int mainMenuOption()
{
    cout << endl << "Chapter 9 Assignment by by Julian Espinoza, Wesley Goo, Hamza Patel, Arturo Islas Mejia";
    cout << endl << "==========================================";
    cout << endl << "1> Pattern of astricks and blanks";
    cout << endl << "2> Guess a number";
    cout << endl << "3> Solve Tower of Hanoi";
    cout << endl << "4> Solve n-Queens";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 3);
    cout << endl << endl << endl;
    return options;
}