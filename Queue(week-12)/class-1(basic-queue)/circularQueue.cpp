// Create Circular Queue
#include <iostream>
using namespace std;

class CirQueue
{

public:
    // properties
    int *arr;
    int size;
    int front;
    int rear;

    // ctor
    CirQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Functions
    void push(int data)
    {
        // Queue Full
        if ((front == 0 && rear == size - 1) ||
            (rear == front - 1))
        {
            cout << "Queue is Full" << endl;
            return;
        }
        // single element
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        // Circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        // Normal flow
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {
        // empty check
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
        }
        // single element
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // circular nature
        else if (front == size - 1)
        {
            front = 0;
        }
        // normal case
        else
        {
            front++;
        }
    }
};

int main()
{
    CirQueue q(10);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(10);

    q.pop();
    q.pop();

    q.push(10);
    q.push(10);

    q.push(10);

    return 0;
}