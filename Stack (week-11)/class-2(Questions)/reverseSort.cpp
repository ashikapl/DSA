// Reverse sort in stack
#include <iostream>
#include <stack>
using namespace std;

void reverseSort(stack<int> &s, int target)
{
    if (s.empty() || s.top() < target)
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    reverseSort(s, target);

    s.push(topElement);
}

void solve(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int topElement = s.top();
    s.pop();

    solve(s);

    reverseSort(s, topElement);
}

int main()
{
    stack<int> s;

    s.push(4);
    s.push(5);
    s.push(1);
    s.push(9);
    s.push(12);
    s.push(60);

    solve(s);

    cout << "Printint->" << endl;

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}