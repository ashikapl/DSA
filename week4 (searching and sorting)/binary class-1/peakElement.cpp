// Find the peak element with the help of binary-search
#include <iostream>
#include <vector>
using namespace std;

int peakElement(vector<int> arr, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            // right search
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }

    return e;
}

int main()
{
    vector<int> arr = {0, 10, 5, 4};
    int n = arr.size();

    int ans = peakElement(arr, n);

    cout << "Index of Peak Element is:- " << ans;

    return 0;
}