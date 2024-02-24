// Place n-Queens in n*n matrix(board)
#include <iostream>
#include <vector>
using namespace std;

void printSolution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
    // check ki current position pr queen hai ya nhi
    int i = row;
    int j = col;

    // row check
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        j--;
    }

    // upper left check
    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        i--;
        j--;
    }

    // bottom left check
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        i++;
        j--;
    }

    return true;
}

void solve(vector<vector<char>> &board, int col, int n)
{
    // base case
    if (col >= n)
    {
        printSolution(board, n);
        return;
    }

    // ek case solve // baaki recursion solve kar legaa
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';

            // recursion call
            solve(board, col + 1, n);
            // backtracking
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));

    int col = 0;

    solve(board, col, n);

    return 0;
}