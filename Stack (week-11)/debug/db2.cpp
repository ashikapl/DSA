#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreaterElementLeft(const vector<int> &input, int n)
{
    vector<int> left(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && input[s.top()] <= input[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            left[i] = s.top();
        }
        s.push(i);
    }

    // Print the results
    cout << "Next Greater Elements to the Left:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " : " << (left[i] == -1 ? -1 : input[left[i]]) << endl;
    }
}

int main()
{
    vector<int> input{1, 2, 3, 4};
    int n = 4;

    nextGreaterElementLeft(input, n);

    return 0;
}
