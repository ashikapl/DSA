// print array using recursion
#include <iostream>
using namespace std;

void printArray(int arr[], int n, int i)
{
    // base case
    if (i >= n)
        return;

    // recursive relation - baki recursion smbhal lega
    printArray(arr, n, i + 1);

    // processing - 1 case solve karliya
    cout << arr[i] << " ";
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;

    int i = 0;

    printArray(arr, n, i);

    return 0;
}