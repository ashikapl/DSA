#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreaterElementRight(vector<int> input, int n)
{
    vector<int> right(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(i);
            continue;
        }
        while (!s.empty() && input[s.top()] < input[i])
        {
            right[s.top()] = input[i];
            s.pop();
        }
        s.push(i);
    }

    // Print the results
    cout << "Next Greater Elements to the right:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " : " << (right[i] == -1 ? -1 : right[i]) << endl;
    }
}

int main()
{
    vector<int> input{1, 2, 3, 4};
    int n = 4;

    nextGreaterElementRight(input, n);

    return 0;
}
