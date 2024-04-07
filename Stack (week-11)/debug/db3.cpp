#include <iostream>
#include <stack>

using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
    // Base Case: If input stack is empty, return
    if (input.empty())
    {
        return;
    }

    // Pop the top element from input stack
    int x = input.top();
    input.pop();

    // Recursively call reverseStack() on remaining elements
    reverseStack(input, extra);

    // Move all elements from input stack to extra stack
    while (!input.empty())
    {
        extra.push(input.top());
        input.pop();
    }

    // Push the popped element back onto input stack
    input.push(x);

    // Move all elements from extra stack back to input stack
    while (!extra.empty())
    {
        input.push(extra.top());
        extra.pop();
    }
}

int main()
{
    stack<int> input;
    stack<int> extra;

    // Push some elements into input stack
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);
    input.push(5);

    cout << "Original Stack:" << endl;
    stack<int> temp = input; // Create a temporary copy to print without modifying the original
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the stack
    reverseStack(input, extra);

    cout << "Reversed Stack:" << endl;
    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;

    return 0;
}
