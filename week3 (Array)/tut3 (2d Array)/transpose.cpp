// Transpose rows into columns

#include <iostream>
using namespace std;

// transpose function
void transposeRowTOCol(int arr[][4], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = i; j < c; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

// Printing array
void printArray(int arr[][4], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[4][4] = {{1, 4, 3}, {7, 8, 9}, {3, 2, 5}, {7, 7, 7}};
    int r = 4;
    int c = 4;

    cout << "Array before Transpose:-- " << endl;
    printArray(arr, r, c);

    // int transpose[3][3];

    transposeRowTOCol(arr, r, c);

    cout << "Array after Transpose:-- " << endl;
    printArray(arr, r, c);

    return 0;
}