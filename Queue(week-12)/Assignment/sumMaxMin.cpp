// Sum of max & min element of all the subarray of size K
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int sumOfMaxMin(vector<int> &arr, int n, int k)
    {
        deque<int> dq,dq2;
        int ans = 0;
        
        for(int i = 0; i < k; i++)
        {
            while(!dq.empty() && arr[i] >= arr[dq.back()])
            {
                dq.pop_back();
            }
            while(!dq2.empty() && arr[i] <= arr[dq2.back()])
            {
                dq2.pop_back();
            }
            
            dq.push_back(i);
            dq2.push_back(i);
        }
        
        ans += arr[dq.front()] + arr[dq2.front()];
        
        for(int i = k; i < n; i++)
        {
            if(!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }
            if(!dq2.empty() && i - dq2.front() >= k)
            {
                dq2.pop_front();
            }
            
            while(!dq.empty() && arr[i] >= arr[dq.back()])
            {
                dq.pop_back();
            }
            while(!dq2.empty() && arr[i] <= arr[dq2.back()])
            {
                dq2.pop_back();
            }
            
            dq.push_back(i);
            dq2.push_back(i);
            
            ans += arr[dq.front()] + arr[dq2.front()];
        }

        return ans;
}

int main()
{
    vector<int> v{2,6,-1,-3,-4,7,1,0};
    int n = 8;
    int k = 3;
     
    cout << sumOfMaxMin(v,n,k) << endl;

    return 0;
}