// Kth smallest element from Priority-Queue(Max-heap)
// T.C -> O(N) && S.C -> O(K)
#include<iostream>
#include<queue>
using namespace std;

int kthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> pq;

    for(int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k; i < n; i++)
    {
        int element = arr[i];
        if(element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();

    return ans;
}

int main()
{
    int arr[] = {2,5,7,3,8,13,15};
    int n = 7;
    int k = 3;

    int ans = kthSmallestElement(arr,n,k);
    
    cout << "Kth smallest Element is: " << ans << endl;

    return 0;
}