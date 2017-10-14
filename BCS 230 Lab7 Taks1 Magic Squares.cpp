/**
   Programmer's name    : Stanley
   Class                : BCS 230 Foundations of Computer Programming II
   Date                 : 10/09/2017
   Lab                  : Lab 7 Task 1
   Professor's name     : Moaath Alrajab
   Software uses        : Code:blocks
**/

/*
    *********** Magic Squares *************
    One interesting application of two-dimensional arrays is
    magic squares. A magic square is a square matrix in
    which the sum of every row, every column, and both
    diagonals is the same. Magic squares have been
    studied for many years, and there are some
    particularly famous magic squares.

                        +---+---+---+
                        | 2 | 7 | 6 | => 15
                        +-----------+
                        | 9 | 5 | 1 | => 15
                        +---+---+---+
                        | 4 | 3 | 8 | => 15
                        +---+---+---+
                       /  |   |   |  \
                      15 15  15  15  15

    In this exercise you will modify the provided shell code
    to determine whether a square is magic or not assuming
    that all elements are between 1 and 9.

    Your program should simulate a magic square using
    two-dimensional 3x3 array. It should have a Boolean
    function isMagicSquare that accepts the array as an argument
    and returns true if it is determines it is a Magic square and
    false it not as shown in the shell code bellow.

*/

#include <iostream>
using namespace std;

const int SIZE = 3;  // Arrays will be 2-D 3x3 arrays

// Function prototype
void inputMagicSq(int[][SIZE],int);
void showArray (int[][SIZE]);
bool isMagicSquare(int[][SIZE]);

int main()
{
    int array1[SIZE][SIZE];
    cout << "Enter square elements 3x3. \n\n";
    //ToDo 1: call the inputMagicSq to enter values
    inputMagicSq(array1, SIZE);
    cout << "You entered. \n\n";
    //ToDo 2:  call showArray to print elements
    showArray (array1);
    //ToDO 3: check if the square is magic or not
    bool square = isMagicSquare(array1);

    if(square){
        cout << "The numbers you entered are a magic Squares" << endl;
    }else{
        cout << "The numbers you entered are not a magic Squares" << endl;
    }


    return 0;
}

/*********************************************************************
 *                             showArray                             *
 * This function displays the contents of the 2D array passed to it. *
 *********************************************************************/
void showArray (int A[][SIZE])
{
    // ToDo: print the square elements
    int length = sizeof(A[0])/sizeof(A[0][0]);
    //Since the number of rows equal to the number of column then we
    //can use one size for both loop
    cout << "+-----+-----+-----+" << endl;
    for(int columns = 0; columns < length; columns++){
        for(int rows = 0; rows < length; rows++){
            cout << "|  " << A[columns][rows] << "  ";
        }
          cout <<"|"<<endl << "+-----+-----+-----+" << endl;
    }

}

/*********************************************************************
 *                             inputMagicSq                          *
 * This function reads the contents of the 2D array.                 *
 *********************************************************************/
void inputMagicSq(int sqArr[][SIZE], int size){
    //ToDo: read square elements
    int count = 0;

    for(int columns = 0; columns < size; columns++){
        for(int rows = 0; rows < size; rows++){
            cout << "Enter your " << ++count << " number: ";
            cin >> sqArr[columns][rows];
        }
    }
}

/***************************************************************
 *                           isMagicSquare                     *
 * This Boolean function determines if the 3 x 3 array of      *
 * integers passed to it is a magic square or not. A magic     *
 * square must contain one instance of each digit 1-9 and      *
 * every row, column, and diagonal must sum to the same value. *
 ***************************************************************/
bool isMagicSquare(int A[][SIZE])
{
    //Determine the number of element in a row
    int rowLength = sizeof(A)/sizeof(A[0]);

    //Declare three variables to calculate the sum of each row
    int sum1 = 0, sum2 = 0, sum3 = 0;

    // ToDo: Check column sums
    for (int row = 0; row < rowLength; row++)
    {
       // ToDo: Check each column separately
       sum1 += A[row][0];
       sum2 += A[row][1];
       sum3 += A[row][2];
    }
    //Check if each row are equal
    if (!(sum1 == sum2 && sum2 == sum3))
        return false;

    // If column sums are OK, check row sums
    // But first reinitialize the accumulators
    sum1 = sum2 = sum3 = 0;

    //Determine the number of element in a column
    int colLength = sizeof(A[0])/sizeof(A[0][0]);

    for (int col = 0; col < colLength; col++)
    {
       // ToDo: Check each row separately
       sum1 += A[0][col];
       sum2 += A[1][col];
       sum3 += A[2][col];
    }
    //Check if all the column are equals
    if (!(sum1 == sum2 && sum2 == sum3))
        return false;

    // If row sums are also OK, compute the 2 diagonal sums
    // Let sum3 continue to hold the value the diagonal sums should equal
    sum1 = A[0][0] + A[1][1] + A[2][2];  // Right diagonal
    sum2 = A[0][2] + A[1][1] + A[2][0];  // Left diagonal
    if (!(sum1 == sum2 && sum2 == sum3))
        return false;

    // If we got this far. Everything adds up to the same value.
    return true;
}
