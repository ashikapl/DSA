// Find the odd occuring elment in an array //
//  is question me sare number do-do ke pair me honge or koi ek number single hoga wahi humara answer hain
#include <iostream>
#include <vector>
using namespace std;

int findOdd(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (s == e)
        {
            return s;
        }
        else if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                // right search
                s = mid + 2;
            }
            else
            {
                // left search
                e = mid; // yaha pr mid - 1 isliye nahi kiya kyuki mid bhi ans ho skta he becoz the ans is always on even index
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                // right search
                s = mid + 1;
            }
            else
            {
                // left search
                e = mid - 1; // yaha isliye kiya ek kyuki yaha index ki value odd index pr he
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 8, 8, 9, 9, 10};

    int ans = findOdd(arr);

    cout << "Index of " << ans << " is:--> " << arr[ans] << endl;

    return 0;
}