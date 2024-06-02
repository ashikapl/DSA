// Book Allocation problem
#include <iostream>
#include <numeric>
using namespace std;

bool isPossible(int A[], int N, int M, int mid)
{
    int pageSum = 0;
    int c = 1; // Count of M = no. of student

    for (int i = 0; i < N; i++)
    {
        if (A[i] > mid)
        {
            return false;
        }
        else if (pageSum + A[i] > mid)
        {
            c++;
            pageSum = A[i];
            if (c > M)
            {
                return false;
            }
        }
        else
        {
            pageSum += A[i];
        }
    }

    return true;
}

int binarySearch(int A[], int N, int M)
{
    if (M > N)
        return -1;

    int start = 0;
    int end = accumulate(A, A - N, 0);
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(A, N, M, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int A[4] = {12, 34, 67, 90};
    int N = 4;
    int M = 2;

    int ans = binarySearch(A, N, M);

    cout << ans;

    return 0;
}