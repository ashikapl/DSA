// Self Create Stack
#include <iostream>
using namespace std;

class Stack
{
public:
    // properties -- data members

    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // Functions
    void push(int data)
    {
        if (size - top > 1)
        {
            // space available
            // insert
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow, Can't delete!" << endl;
        }
        else
        {
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "There is no element in Stack!" << endl;
        }
        else
        {
            return arr[top];
        }
    }

    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // creation
    Stack s(10);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    cout << "Size of Stack: " << s.getSize() << endl;

    // s.pop();

    return 0;
}