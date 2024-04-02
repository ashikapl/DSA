#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // creation
    stack<int> st;

    // insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // remove
    st.pop(); // last element in the stack is removed from it

    // top element in present in stack
    cout << "Top element in Stack is: " << st.top() << endl; // In LIFO form

    // size
    cout << "Size of stack: " << st.size() << endl;

    // empty check
    if (st.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    // Print Stack elements
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // elements are print in reverse order when we push / pop it
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}