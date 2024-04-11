// Interleave two halves of queue (first & second half interleave) (TC -> O(N) & (SC -> O(N))
#include <iostream>
#include <queue>
using namespace std;

void interLeave(queue<int> &q)
{
    int n = q.size();
    int k = n / 2;
    queue<int> q2;

    if (q.empty())
    {
        return;
    }

    for (int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();

        q2.push(temp);
    }

    while (!q.empty() && !q2.empty())
    {
        int first = q2.front();
        q2.pop();

        q.push(first);

        int second = q.front();
        q.pop();

        q.push(second);
    }

    if (n & 1)
    {
        int temp = q.front();
        q.pop();

        q.push(temp);
    }
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    // q.push(9);

    interLeave(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}