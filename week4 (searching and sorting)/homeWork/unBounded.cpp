// Unbounded Search
// Find the element in an infinite array //
#include <iostream>
#include <vector>
using namespace std;

int bs(vector<int> myVector[], int start, int end, int x)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (myVector[mid] == x)
        {
            return mid;
        }
        else if (myVector[mid] > x)
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

vector<int> exponentialSrch(vector<int> myVector[], int n, int x)
{
    int i = 0;
    int j = 1;
    while (myVector[j] < x)
    {
        i = j;
        j = j * 2;
    }
    return bs(myVector, i, j, x);
}

int main()
{
    vector<int> myVector;
    int n;

    cout << "Enter the size of the vector: ";
    cin >> n;

    myVector.resize(n);

    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> myVector[i];
    }

    int x;
    cout << "Enter the target value:- ";
    cin >> x;

    int ans = exponentialSrch(myVector, n, x);

    cout << "Index is:- " << endl;

    return 0;
}
