// Find the total occurence of array by binary funtion
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int firstOccurence(vector<int> v, int n, int target)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    int ans = -1;

    while (start <= end)
    {
        if (v[mid] == target)
        {
            ans = v[mid];
            // search in left
            end = mid - 1;
        }
        else if (target < v[mid])
        {
            // searh in right
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int lastOccurence(vector<int> v, int n, int target)
{
    int s = 0;     // s = start
    int e = n - 1; // e = end
    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {
        if (v[mid] == target)
        {
            ans = mid;
            // Search in right
            s = mid + 1;
        }
        else if (target > v[mid])
        {
            // search in left
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> v{1, 2, 3, 3, 4, 4, 4, 5, 6};
    int n = v.size();
    int target = 4;

    int firstOcc = firstOccurence(v, n, target);

    cout << "Index of first Occurence is:- " << firstOcc << endl;

    int lastOcc = lastOccurence(v, n, target);

    cout << "Index of last Occurence is:- " << lastOcc << endl;

    int totalResult = lastOcc - firstOcc + 1;

    cout << "Total occurence is:- " << totalResult << endl;

    return 0;
}