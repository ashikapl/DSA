// find the number which have only 3 factor //
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = 20;

    for (int i = 0; i < size; i++)
    {
        int squareNum = arr[i];
        if (squareNum * squareNum == arr[i])
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}