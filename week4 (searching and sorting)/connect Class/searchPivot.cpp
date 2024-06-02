// search Pivot element in an sorted and rotated array
#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (s == e)
        {
            // single element
            return s;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }
        else if (arr[s] > arr[mid]) // here s is starting element
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

int binarySearch(vector<int> arr, int target, int right, int left)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] > target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> arr{9, 10, 2, 4, 6, 8};
    int target = 2;

    int pivotIndex = findPivot(arr);

    cout << "Index --> " << pivotIndex << endl;

    int ans = 0;
    if (target >= arr[0] && target <= arr[pivotIndex])
    {
        ans = binarySearch(arr, target, 0, pivotIndex);
        cout << "Index of target elemet is:--> " << ans;
    }
    else
    {
        ans = binarySearch(arr, target, pivotIndex + 1, arr.size() - 1);
        cout << "Index of target elemet is:--> " << ans;
    }

    return 0;
}