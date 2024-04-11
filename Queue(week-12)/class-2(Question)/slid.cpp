// First negative integer in every window of size k
#include<iostream>
#include<deque>
using namespace std;

void solve(int arr[], int n, int k)
{
    deque<int> q;

    // Process first window of size k
    for(int i = 0; i < k; i++)
    {
        if(arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    for(int i = k; i < n; i++)
    {
        if(q.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << arr[q.front()] << " ";
        }

        // out of window elements ko remove krdo
        while((!q.empty()) && (i - q.front() >= k))
        {
            q.pop_front();
        }

        if(arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    if(q.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << arr[q.front()] << " ";
        }
}

int main()
{
    int arr[] = {12,-1,-7,8,-15,30,16,28};
    int n = 8;

    int k = 2;

    solve(arr, n, k);

    return 0;
}