// Check the array is sorted or not using recursion
#include <iostream>
#include <vector>
using namespace std;

bool checkSort(vector<int> &arr, int &n, int i)
{
    // base case
    if (i == n - 1)
        return true;

    // processing
    if (arr[i + 1] < arr[i])
        return false;

    // R.R
    return checkSort(arr, n, i + 1);
}

int main()
{
    vector<int> arr{1, 2, 3, 5, 4};
    int n = arr.size();

    int i = 0;

    bool isSorted = checkSort(arr, n, i);

    if (isSorted)
    {
        cout << "Array is sorted!" << endl;
    }
    else
    {
        cout << "Array is not sorted!" << endl;
    }

    return 0;
}