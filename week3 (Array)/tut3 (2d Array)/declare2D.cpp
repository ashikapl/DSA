#include <iostream>
using namespace std;

int main()
{
    // declaring 2d array
    // int arr[3][3];

    // initializing 2d array
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Printing 2d array with the help of loop
    // Outer loop for Row
    cout << "Row-Wise -->" << endl;
    for (int i = 0; i < 3; i++)
    {
        // inner loop for column
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Outer loop for Row
    cout << "Column-Wise -->" << endl;
    for (int i = 0; i < 3; i++)
    {
        // inner loop for column
        for (int j = 0; j < 3; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}