// Butterfly star pattern //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // Stars Half Pyramid //
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }

        // Spaces Full Pyramid //
        for (int j = 0; j < 2 * (n - i) - 2; j++)
        {
            cout << "  ";
        }

        // Stars Half Pyramid //
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        // Stars of half pyramid //
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }

        // Spaces Full Pyramid //
        for (int j = 0; j < 2 * (n - i) - 2; j++)
        {
            cout << "  ";
        }

        // Stars Half Pyramid //
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}