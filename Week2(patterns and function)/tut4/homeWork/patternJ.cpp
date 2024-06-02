// Fancy pattern #3 //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        // Stars and numbers //
        for (int j = 1; j <= i + 1; j++)
        {
            if (j == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << j - 1 << " ";
            }
        }

        // Reverse counting //
        for (int j = i - 1; j >= 0; j--)
        {
            if (j == 0)
            {
                cout << "* ";
            }
            else
            {
                cout << j << " ";
            }
        }

        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        // Stars and numbers //
        for (int j = 1; j <= i + 1; j++)
        {
            if (j == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << j - 1 << " ";
            }
        }

        // Reverse counting //
        for (int j = i - 1; j >= 0; j--)
        {
            if (j == 0)
            {
                cout << "* ";
            }
            else
            {
                cout << j << " ";
            }
        }

        cout << endl;
    }
}