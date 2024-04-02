// Find the middle element in Stack
#include <iostream>
#include <stack>
using namespace std;

void printMiddle(stack<int> &s, int totalSize)
{
    if (s.size() == 0)
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    // base case
    if (s.size() == (totalSize / 2) + 1)
    {
        cout << "Middle element of stack is: " << s.top() << endl;
        return;
    }

    int temp = s.top();
    s.pop();

    // recursive call
    printMiddle(s, totalSize);

    // BackTrack
    s.push(temp);
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    int totalSize = s.size();

    printMiddle(s, totalSize);

    return 0;
}