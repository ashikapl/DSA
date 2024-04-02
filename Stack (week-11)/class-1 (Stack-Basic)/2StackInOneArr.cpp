// 2 Stack in one Array
#include <iostream>
using namespace std;

class Stack
{
    // properties

    int *arr;
    int size;
    int top1;
    int top2;

    // functions

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "OVERFLOW in Stack 1" << endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "UNDERFLOW in stack 1" << endl;
        }
        else
        {
            top1--;
        }
    }
    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "OVERFLOW in Stack 2" << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "UNDERFLOW in stack 2" << endl;
        }
        else
        {
            top2++;
        }
    }
};

int main()
{
    return 0;
}
