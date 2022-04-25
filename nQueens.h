const int QUEENSVLAUE = 100;
//Precondition:takes the board, the size of the board, and the number of queens on the board
//Postcondition: returns ture if you found a soultion flase if you havent.
bool endGame(int** nQueens, int sizeOfBoard, int numberOfQueensOnBoard)
{
    int pointsChecked = 0;
    if (numberOfQueensOnBoard == sizeOfBoard)
    {
        return true;
    }

    return false;
}

//Precondition: takes input user from board size
//Postcondition: displays board size based upon user input
void displayBoard(int** nQueens, int sizeOfBoard)
{
    // displays the bored
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {
            if (j == 0)
                cout << "|";
            if (nQueens[i][j] == QUEENSVLAUE)
                cout << "Q";
            else if (nQueens[i][j] > 0)
                cout << "*";
            else
                cout << " ";
            cout << "|";
            if (j == sizeOfBoard - 1)
                cout << endl;
        }
        for (int i = 0; i < sizeOfBoard; i++)
        {
            if (i == 0)
                cout << "-";
            cout << "--";
            if (i == sizeOfBoard - 1)
                cout << endl;
        }
    }
    cout << endl << endl << endl;
}

//Precondition: takes the board, the size of the board, the row and column you want to places a queen on
//Postcondition: returns true if there is no overlap and false if there is overlap
bool isSafe(int** nQueens, int sizeOfBoard, int row, int column)
{
    if (nQueens[row][column] == QUEENSVLAUE)
    {
        //cout << "Invalid. A queen is already placed here. Try Again." << endl;
        return false;
    }
    else if (nQueens[row][column] > 0)
    {
        //cout << "Invalid. in the path of a current Queen. Try Again." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

//Precondition: takes the board, the size of the board, the row and column you want to places a queen on and the number of queens on the board
//Postcondition: adds a queen to the board
void addQueen(int**& nQueens, int sizeOfBoard, int row, int column, int& numberOfQueensOnBoard)
{


    if (nQueens[row][column] == QUEENSVLAUE)
    {
        //cout << "Invalid. A queen is already placed here. Try Again." << endl;
        return;
    }
    else if (nQueens[row][column] > 0)
    {
        //cout << "Invalid. in the path of a current Queen. Try Again." << endl;
        return;
    }
    else
    {
        nQueens[row][column] = QUEENSVLAUE;
        numberOfQueensOnBoard++;
    }


    for (int i = 0; i < sizeOfBoard; i++)
    {

        if (column != i)
            nQueens[row][i] += 1;
    }

    for (int i = 0; i < sizeOfBoard; i++)
    {
        if (row != i)
            nQueens[i][column] += 1;
    }

    //handle diagonal line going bottom right.
    int temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = column; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row + temp1 && j == column + temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] += 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = column; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row - temp1 && j == column - temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] += 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = column; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row + temp1 && j == column - temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] += 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = column; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row - temp1 && j == column + temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] += 1;
            }

        }
    }

}

//Precondition: takes the board, the size of the board, the row and column you want to remove a queen from and the number of queens on the board
//Postcondition: removes a queen from the board
void removeQueen(int**& nQueens, int sizeOfBoard, int row, int column, int& numberOfQueensOnBoard)
{

    if (nQueens[row][column] == QUEENSVLAUE)
    {
        nQueens[row][column] = 0;
        numberOfQueensOnBoard--;
    }
    else if (nQueens[row][column] > 0)
    {
        //cout << "Invalid. This is a Queens path not a Queen. Try Again." << endl;
        return;
    }
    else
    {
        //cout << "Invalid. This is a blank space. Try Again." << endl;
        return;
    }

    nQueens[row][column] = 0;

    for (int i = 0; i < sizeOfBoard; i++)
    {

        if (column != i)
            nQueens[row][i] -= 1;
    }

    for (int i = 0; i < sizeOfBoard; i++)
    {
        if (row != i)
            nQueens[i][column] -= 1;
    }

    int temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = column; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row + temp1 && j == column + temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] -= 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = column; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row - temp1 && j == column - temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] -= 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = column; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row + temp1 && j == column - temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] -= 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = column; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row - temp1 && j == column + temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] -= 1;
            }

        }
    }
}

bool check(int**& nQueens, int sizeOfBoard, int row, int column)
{
    if (nQueens[row][column] == QUEENSVLAUE)
    {
        //cout << "Invalid. A queen is already placed here. Try Again." << endl;
        return false;
    }
    else if (nQueens[row][column] > 0)
    {
        //cout << "Invalid. in the path of a current Queen. Try Again." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool solvenQueens(int **&nQueens, int sizeOfBoard, int row, int& numberOfQueensOnBoard)
{

    if (numberOfQueensOnBoard >= sizeOfBoard)
        return true;
    for (int i = 0; i < sizeOfBoard; i++)
    {
        if (check(nQueens, sizeOfBoard, row, i))
        {
            addQueen(nQueens, sizeOfBoard, row, i, numberOfQueensOnBoard);
            if (solvenQueens(nQueens, sizeOfBoard, row + 1, numberOfQueensOnBoard))
                return true;

            removeQueen(nQueens, sizeOfBoard, row, i, numberOfQueensOnBoard);
        }
    }

    return false;
}

//Precondition: none
//Postcondition: solves the nQueens board
void nQueens()
{
    //left int is row, right int is column

    int sizeOfBoard = inputInteger("Enter a number (1...100) if queens: ", 1, 100);
    int column = inputInteger("Enter the column (1.." + to_string(sizeOfBoard) + ") to place the first queen: ", 1, sizeOfBoard);
    int row = 0;
    int numberOfQueens = 0;
    int** nQueens = new int* [sizeOfBoard];

    //creates the array and fills the array with blank spaces
    for (int i = 0; i < sizeOfBoard; i++) {

        // Declare a memory block
        // of size sizeOfBoard
        nQueens[i] = new int[sizeOfBoard];
    }

    // Traverse the 2D array
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {

            // Assign values to the
            // memory blocks created
            nQueens[i][j] = 0;
        }
    }
    addQueen(nQueens, sizeOfBoard, 0, column-1, numberOfQueens);
    if (solvenQueens(nQueens,sizeOfBoard,1,numberOfQueens) == false) 
    {
        cout << "Solution does not exist " << endl;
        for (int i = 0; i < sizeOfBoard; i++)    //To delete the inner arrays
            delete[] nQueens[i];
        delete[] nQueens;
        return;
    }
    displayBoard(nQueens, sizeOfBoard);

    //Delete the array created
    for (int i = 0; i < sizeOfBoard; i++)    //To delete the inner arrays
        delete[] nQueens[i];
    delete[] nQueens;
}
