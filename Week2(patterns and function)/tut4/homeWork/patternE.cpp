// Numeric Hollow Half Pyramid //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start = 2;
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
            {
                cout << "1 ";
            }
            else if (j == i)
            {
                cout << i + 1;
            }
            else if (i == n - 1)
            {
                cout << start << " ";
                start = start + 1;
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

// one more condition to print Numeric half pyramid //

// for (int row = 0; row < n; row++)
// {
//     for (int col = 0; col < row + 1; col++)
//     {
//         if (col == 0 || col == row || row == n - 1)
//         cout << col + 1;
//         else{
//             cout << " ";
//         }
//     }
// }