#include <iostream>
using namespace std;

void findMax(int arr[], int n, int i, int &max)
// here max is pass by reference becoz the value of max must be change in main funtion
{
    // base case
    if (i >= n)
        return;

    // 1 case solve kar diya
    if (arr[i] > max)
    {
        max = arr[i];
    }

    // baki recursion smbhal lega
    findMax(arr, n, i + 1, max);
}

void findMin(int arr[], int n, int i, int &min)
// here min is pass by reference becoz the value of min must be change in main funtion
{
    // base case
    if (i >= n)
        return;

    // 1 case solve kar diya
    if (arr[i] < min)
    {
        min = arr[i];
    }

    // baki recursion smbhal lega
    findMin(arr, n, i + 1, min);
}

int main()
{
    int arr[] = {11, 21, 31, 4, 54, 14};
    int n = 6;

    int max = INT_MIN;
    int min = INT_MAX;

    int i = 0;

    findMax(arr, n, i, max);
    findMin(arr, n, i, min);

    cout << "Maximum number is:- " << max << endl;
    cout << "Minimum number is:- " << min << endl;

    return 0;
}