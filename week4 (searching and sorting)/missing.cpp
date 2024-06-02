#include <iostream>
#include <vector>
using namespace std;

int findProduct(int A[], int B[], int n)
{
    int max = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (B[i] < mini)
        {
            mini = B[i];
        }
    }
    int ans = mini * max;
    return ans;
}

int main()
{
    int A[] = {5, 7, 9, 3, 6, 2};
    int B[] = {1, 2, 6, 4, 7, 9};
    int n = 6;

    cout << findProduct(A, B, n);

    return 0;
}