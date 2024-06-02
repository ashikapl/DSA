// Taking input and Printing output 2d Array

#include <iostream>
using namespace std;

int main()
{
    int arr[3][3];

    // Taking input

    cout << "Row-Wise: --> " << endl;

    // for row
    for (int i = 0; i < 3; i++)
    {
        // for column
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Printing output

    // for row
    for (int i = 0; i < 3; i++)
    {
        // for column
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Taking input

    cout << "Column-Wise: --> " << endl;

    // for row
    for (int i = 0; i < 3; i++)
    {
        // for column
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[j][i];
        }
    }

    // Printing output

    // for row
    for (int i = 0; i < 3; i++)
    {
        // for column
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}