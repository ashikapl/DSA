// Find the last occurence of the array with the help of binary-search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    vector<int> v = {1, 2, 3, 3, 3, 4, 5};
    int n = v.size();

    int target = 3;

    int lastOcc = lastOccurence(v, n, target);

    cout << "Index of last-occurence is:- " << lastOcc << endl;

    // using binary funtion to find last occurence
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5};

    auto i = upper_bound(arr.begin(), arr.end(), 3);

    cout << "Index by binary-funtion is:- " << i - arr.begin();

    return 0;
}