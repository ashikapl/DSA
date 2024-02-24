// n - Queen optimize solution with the help of map
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLeftDiagonalCheck;
unordered_map<int, bool> bottomLeftDiagonalCheck;

void printSolution(vector<vector<char>> &chessBoard, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chessBoard[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<char>> &chessBoard, int n, int col, int row)
{
    if (rowCheck[row] == true)
    {
        return false;
    }
    else if (upperLeftDiagonalCheck[n - 1 + col - row] == true)
    {
        return false;
    }
    else if (bottomLeftDiagonalCheck[row + col] == true)
    {
        return false;
    }

    return true;
}

void solve(vector<vector<char>> &chessBoard, int n, int col)
{
    // base case
    if (col >= n)
    {
        printSolution(chessBoard, n);
        return;
    }

    // ek case solve ans call recursion
    for (int row = 0; row < n; row++)
    {
        if (isSafe(chessBoard, n, col, row))
        {
            chessBoard[row][col] = 'Q';
            rowCheck[row] = true;
            upperLeftDiagonalCheck[n - 1 + col - row] = true;
            bottomLeftDiagonalCheck[row + col] = true;

            // recursion
            solve(chessBoard, n, col + 1);

            // backTracking
            chessBoard[row][col] = '.';
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n - 1 + col - row] = false;
            bottomLeftDiagonalCheck[row + col] = false;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<char>> chessBoard(n, vector<char>(n, '.'));

    int col = 0;

    solve(chessBoard, n, col);

    return 0;
}