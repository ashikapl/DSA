// Find the first occurence of an element using an in-bulit function or without funtion//
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

int main()
{
    vector<int> v{1, 2, 3, 3, 4, 4, 4, 5, 6};
    int n = v.size();
    int target = 4;

    int firstOcc = firstOccurence(v, n, target);

    cout << "Index of first Occurence is:- " << firstOcc << endl;

    // using binary-function to find first occurence
    vector<int> arr{1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 6};

    auto i = lower_bound(arr.begin(), arr.end(), 4);
    cout << "Index by first-occurence function:- " << i - arr.begin();

    return 0;
}