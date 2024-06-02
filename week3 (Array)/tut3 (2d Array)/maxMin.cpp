// Find maximum and minimum value of 2d array

#include <iostream>
using namespace std;

// find maximum value
int findMax(int arr[][3], int rows, int cols)
{
    int max = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

// find minimum value
int findMin(int arr[][3], int rows, int cols)
{
    int min = INT_MAX;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int main()
{
    int arr[3][3] = {{1, 5, 6}, {6, 7, 9}, {2, 3, 11}};
    int rows = 3;
    int cols = 3;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int maxNumber = findMax(arr, rows, cols);

    cout << "The maximum no. is:- " << maxNumber << endl;

    int minNumber = findMin(arr, rows, cols);

    cout << "The minimum no. is:- " << minNumber;

    return 0;
}