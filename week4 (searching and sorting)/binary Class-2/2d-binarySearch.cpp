// Binary search in 2-D array
#include <iostream>
using namespace std;

bool binarySearch(int arr[][3], int row, int col, int target)
{
    int s = 0;
    int totalElement = row * col;
    int e = totalElement - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int rowIndex = mid / col;
        int colIndex = mid % col;
        int element = arr[rowIndex][colIndex];

        if (element == target)
        {
            cout << "Found at " << rowIndex << " " << colIndex << endl;
            return true;
        }
        else if (element < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return false;
}

int main()
{
    int arr[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int row = 4;
    int col = 3;

    int target = 8;

    bool ans = binarySearch(arr, row, col, target);

    if (ans)
    {
        cout << "Found!" << endl;
    }
    else
    {
        cout << "Not Found!" << endl;
    }

    return 0;
}