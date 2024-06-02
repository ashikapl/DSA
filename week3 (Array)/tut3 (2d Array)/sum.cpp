// Sum all the digits in row-wise and column-wise

#include <iostream>
using namespace std;

void findRowSum(int arr[][3], int rows, int cols)
{
    cout << "The sum of rows is:--> " << endl;

    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum = arr[i][j] + sum;
        }
        cout << sum << endl;
    }
}

void findColSum(int arr[][3], int rows, int cols)
{

    cout << "The sum of columns is:--> " << endl;

    for (int i = 0; i < rows; i++)
    {
        int add = 0;
        for (int j = 0; j < cols; j++)
        {
            add = arr[i][j] + add;
        }
        cout << add << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    int rows = 3;
    int cols = 3;

    // Row-Wise
    cout << "Row-Wise-->" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    findRowSum(arr, rows, cols);

    // Column-Wise
    cout << "Column-Wise-->" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    findColSum(arr, rows, cols);

    return 0;
}