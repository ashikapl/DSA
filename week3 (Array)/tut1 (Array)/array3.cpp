// call by reference

// call by reference means actual value of array is pass in function...

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void update(int arr[], int size)
{
    arr[0] = arr[0] + 10;
    printArray(arr, size);
}

int main()
{
    int arr[] = {1, 2};
    int size = 2;

    update(arr, size);

    printArray(arr, size);

    return 0;
}