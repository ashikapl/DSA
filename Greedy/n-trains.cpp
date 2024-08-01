// N-train at a platfrom -> using Greedy Approach
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

int solve(int arrival[], int departure[], int n)
{
    vector<pair<int,int>> arr;

    for(int i = 0; i < n; i++)
    {
        arr.push_back({arrival[i],departure[i]});
    }

    sort(arr.begin(), arr.end(), cmp);

    int count = 1;
    int lastDep = arr[0].second;

    cout << "Arrival at:- " << arr[0].first << " Departure at:- " << arr[0].second << endl;

    for(int i = 1; i < n; i++)
    {
        if(arr[i].first >= lastDep)
        {
            count++;
            lastDep = arr[i].second;

            cout << "Arrival at:- " << arr[i].first << " Departure at:- " << arr[i].second << endl;
        }
    }

    return count;
}

int main()
{
    int n = 4;
    int arrival[] = {5,8,2,4};
    int departure[] = {7,11,6,5};

    int ans = solve(arrival, departure, n);

    cout << "No. of trains can stay on platform: " << ans << endl;

    return 0;
}