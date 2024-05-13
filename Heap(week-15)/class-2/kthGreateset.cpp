// Kth greatest element -> priority_queue(Min Heap)
// T.C -> O(N) && S.C -> O(K)
#include<iostream>
#include<queue>
using namespace std;

int kthGreatestElement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k; i < n; i++)
    {
        int element = arr[i];
        if(element > pq.top())
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
    int k = 4;

    int ans = kthGreatestElement(arr,n,k);
    
    cout << "Kth Greatest Element is: " << ans << endl;

    return 0;
}