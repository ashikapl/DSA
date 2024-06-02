// Hollow Solid diamond //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int r = 0; r < n; r++)
    {
        // spaces //
        for (int c = 0; c < n - r - 1; c++)
        {
            cout << " ";
        }

        // stars //
        for (int c = 0; c < 2 * r + 1; c++)
        {
            if (c == 0 || c == 2 * r)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int r = 0; r < n; r++)
    {
        // spaces //
        for (int c = 0; c < r; c++)
        {
            cout << " ";
        }

        // stars //
        for (int c = 0; c < 2 * n - 2 * r - 1; c++)
        {
            if (c == 0 || c == 2 * n - 2 * r - 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}