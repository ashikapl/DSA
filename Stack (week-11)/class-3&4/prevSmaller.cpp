// Previous Smaller Element -> TC -> O(n)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prevSmaller(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    // left to right -> prev smaller
    for (int i = 0; i < v.size(); i++)
    {
        // store current element
        int curr = v[i];

        // answer in stack
        while (s.top() >= curr)
        {
            s.pop();
        }

        // store in ans when smaller value is find
        ans[i] = s.top();

        // include next value
        s.push(curr);
    }

    return ans;
}

int main()
{
    vector<int> v;

    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> ans = prevSmaller(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}