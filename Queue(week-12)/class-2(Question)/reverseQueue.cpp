// Reverse Queue
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> recursiveRev(queue<int> q)
{
    if (q.empty())
    {
        return q;
    }

    int temp = q.front();
    q.pop();

    q = recursiveRev(q);

    q.push(temp);

    return q;
}

void reverse(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        s.push(temp);
    }

    while (!s.empty())
    {
        int ele = s.top();
        s.pop();

        q.push(ele);
    }
}

int main()
{
    queue<int> q;

    q.push(2);
    q.push(5);
    q.push(8);
    q.push(11);
    q.push(14);
    q.push(17);

    queue<int> a = recursiveRev(q);

    while (!a.empty())
    {
        cout << a.front() << " ";
        a.pop();
    }
    cout << endl;

    reverse(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}