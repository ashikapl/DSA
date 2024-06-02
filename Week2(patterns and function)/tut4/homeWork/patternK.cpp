#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    int count = 1;

    // Upper half of the pattern
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == i)
            {
                cout << count << " ";
                count++;
            }
            else
            {
                cout << count << "*";
                count++;
            }
        }
        cout << endl;
    }

    // Lower half of the pattern
    count = count - n;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == i)
            {
                cout << count << " ";
                count++;
            }
            else
            {
                cout << count << "*";
                count++;
            }
        }
        cout << endl;
        count = count - 2 * i + 1;
    }

    return 0;
}
