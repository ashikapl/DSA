// priority Queue -> for min Heap 
#include<iostream>
#include<queue> // here stl queue is include to use priority queue
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > pq;
    // int is int type element
    // vector<int> is container that store the elements
    // greater<int> mean its top value is smallest from all elements 
    // min heap -> parent is smallest from child , here parent->root = top element

    pq.push(23);
    pq.push(34);
    pq.push(12);
    pq.push(4);
    // size = 4

    cout << "top element: " << pq.top() << endl;
    pq.pop();
    
    // after pop size is decrease
    cout << "size: " << pq.size() << endl;

    // next top element
    cout << "top element: " << pq.top() << endl;

    if(pq.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }

    cout << "size: " << pq.size() << endl;

    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    pq.pop();

    // after all elements are pop back size is 0 and pq. is empty

    cout << "size: " << pq.size() << endl;
    if(pq.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }

    return 0;
}