// Flipped Solid diamond //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        // half pyramid left side //
        for (int col = 0; col < n - row; col++)
        {
            cout << "*";
        }

        //  Full pyramid //
        for (int col = 0; col < 2 * row + 1; col++)
        {
            cout << " ";
        }

        // half pyramid right side //
        for (int col = 0; col < n - row; col++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int row = 0; row < n; row++)
    {
        // inverted half pyramid left side //
        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }

        // inverted full pyramid //
        for (int col = 0; col < 2 * n - 2 * row - 1; col++)
        {
            cout << " ";
        }

        // inverted half pyramid right side //
        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }
        cout << endl;
    }
}