// Binary Search using recursion
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &v, int s, int e, int &key)
{
    // base case
    if (s > e)
        return -1;

    // processing
    int mid = s + (e - s) / 2;
    if (v[mid] == key)
        return mid;

    // R.R(2 case in recursion relation)
    if (v[mid] < key)
    {
        return binarySearch(v, mid + 1, e, key); // s = mid + 1 -> right search
    }
    else
    {
        return binarySearch(v, s, mid - 1, key); // e = mid - 1 -> left search
    }
}

int main()
{
    vector<int> v{10, 20, 30, 40, 50, 66, 77, 88, 99};
    int n = v.size();
    int key = 99;

    int s = 0;
    int e = n - 1;

    int ans = binarySearch(v, s, e, key);

    cout << "Answer at index:-> " << ans << endl;

    return 0;
}