#include <iostream>
using namespace std;

bool isSafe(int board[][9], int n, int row, int col, int val)
{
    for (int i = 0; i < n; i++)
    {
        // row check
        if (board[row][i] == val)
        {
            return false;
        }
        // col check
        else if (board[i][col] == val)
        {
            return false;
        }
        // 3*3 box check
        else if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val)
        {
            return false;
        }
    }
    return true;
}

bool solve(int board[][9], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check the cell is empty or not
            if (board[i][j] == 0)
            {
                // try to fill 1->9 value in each cell without repitition
                for (int val = 1; val <= 9; val++)
                {
                    // check the val is safe or not means repitited or not
                    if (isSafe(board, n, i, j, val))
                    {
                        // insert
                        board[i][j] = val;
                        // recursive call
                        bool remainingSolution = solve(board, n);
                        // check
                        if (remainingSolution == true)
                        {
                            return true;
                        }
                        else
                        {
                            // backtracking
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int board[9][9] = {
        {2, 0, 9, 0, 0, 0, 6, 0, 0},
        {0, 4, 0, 8, 7, 0, 0, 1, 2},
        {8, 0, 0, 0, 1, 9, 0, 4, 0},
        {0, 3, 0, 7, 0, 0, 8, 0, 1},
        {0, 6, 5, 0, 0, 8, 0, 3, 0},
        {1, 0, 0, 0, 3, 0, 0, 0, 7},
        {0, 0, 0, 6, 5, 0, 7, 0, 9},
        {6, 0, 4, 0, 0, 0, 0, 2, 0},
        {0, 8, 0, 3, 0, 1, 4, 5, 0}};

    int n = 9;

    solve(board, n);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}