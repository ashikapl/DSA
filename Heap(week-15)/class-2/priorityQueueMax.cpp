// Priority Queue -> similar to Heap -> Max heap(By default)
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> pq; // max heap
    // its top value is max from all the elements you push
    // max heap -> parent is greatest from child here first->parent->root = top-element
    pq.push(3);
    pq.push(5);
    pq.push(7);
    pq.push(2);
    pq.push(9);
    //size = 5

    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "Top element: " << pq.top() << endl;
    
    cout << "Size: " << pq.size() << endl;

    pq.pop();
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "Top element: " << pq.top() << endl;
    pq.pop();

    //  after all the elements pop back size is 0 and pq is empty

    cout << "size: " << pq.size() << endl;
    if(pq.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "Not empty()" << endl;
    }
    


    

    return 0;
}