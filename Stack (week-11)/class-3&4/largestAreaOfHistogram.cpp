// Largest Area of Histogram
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
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }

        // store in ans when smaller value is find
        ans[i] = s.top();

        // include next value
        s.push(i);
    }

    return ans;
}

vector<int> nextSmaller(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    // right to left -> next smaller
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];

        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

int largestRectangularArea(vector<int> &v)
{
    vector<int> prev = prevSmaller(v);
    vector<int> next = nextSmaller(v);

    int maxArea = INT_MIN;
    int size = v.size();

    for (int i = 0; i < size; i++)
    {
        int length = v[i];

        if (next[i] == -1)
        {
            next[i] = size;
        }

        int width = next[i] - prev[i] - 1;

        int area = width * length;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    vector<int> v;

    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    int ans = largestRectangularArea(v);

    cout << "Ans is: " << ans << endl;

    return 0;
}