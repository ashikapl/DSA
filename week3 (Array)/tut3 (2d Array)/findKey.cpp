// find key with the help of bool function//

#include <iostream>
using namespace std;

bool findKey(int arr[][3], int rows, int cols, int key)
{
    cout << "The Key is present or not : - ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == key)
                // agar value mil jaye to 1 means true
                return true;
        }
    }

    // agar value nahi mile to 0 means false
    return false;
}

int main()
{
    int arr[3][3] = {{1, 2, 4}, {6, 4, 6}, {1, 7, 9}};
    int rows = 3;
    int cols = 3;

    // Printing row-wise array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int key = 20;
    cout << findKey(arr, rows, cols, key);

    return 0;
}