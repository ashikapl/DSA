// find the nearly sorted array (NSR) using Binary search //
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    // int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        if (mid - 1 >= s && arr[mid - 1] == target)
        {
            return mid - 1;
        }
        if (mid + 1 <= e && arr[mid + 1] == target)
        {
            return mid + 1;
        }
        if (target > arr[mid])
        {
            // right search
            s = mid + 2;
        }
        else
        {
            // left search
            e = mid - 2;
        }
        // int mid = s + (e - s) / 2;
    }

    return -1;
}

int main()
{
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};

    int target = 50;

    int ans = binarySearch(arr, target);

    cout << "The index of " << target << " is:-> " << ans << endl;

    return 0;
}