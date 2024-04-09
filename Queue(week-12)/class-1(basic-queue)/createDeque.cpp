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
    void pushRear(int data)
    {
        // Queue Full
        if (front == 0 && rear == size - 1 || (rear == front - 1))
        {
            cout << "Queue is Full" << endl;
            return;
        }
        // single element
        else if (front == -1)
        {
            front = rear = 0;
        }
        // Circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        // Normal flow
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    void pushFront(int data)
    {
        // Queue Full
        if (front == 0 && rear == size - 1 || (rear == front - 1))
        {
            cout << "Queue is Full" << endl;
            return;
        }
        // single element
        else if (front == -1)
        {
            front = rear = 0;
        }
        // Circular nature
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        // Normal flow
        else
        {
            front--;
        }
        arr[front] = data;
    }

    void popFront()
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
            arr[front] = -1;
            front = 0;
        }
        // normal case
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void popRear()
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
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        // normal case
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CirQueue d(10);

    d.pushRear(12);
    d.pushRear(1);
    d.pushRear(11);
    d.pushRear(2);
    d.pushRear(122);
    d.pushRear(14);
    d.pushRear(101);
    d.pushRear(15);
    d.pushRear(10);
    d.pushRear(1000);

    d.print();

    d.popRear();
    d.popRear();

    d.print();

    d.popFront();
    d.popFront();

    d.pushFront(200);

    d.print();

    return 0;
}