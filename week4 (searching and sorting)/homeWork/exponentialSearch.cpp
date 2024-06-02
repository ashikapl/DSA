// Exponential Search using Binary Search
#include <iostream>
using namespace std;

int bsearch(int arr[], int start, int end, int x)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int exponentialSrch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
    {
        i = i * 2; // or i*=2 or i = i << 1
    }

    return bsearch(arr, i / 2, min(i, n - 1), x); // here i/2 is start and i is index after i=i*2 and n-1 is last index
}

int main()
{
    int arr[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(arr) / sizeof(int);
    int x = 56;

    int ans = exponentialSrch(arr, n, x);

    cout << "Index of x is:--> " << ans;

    return 0;
}