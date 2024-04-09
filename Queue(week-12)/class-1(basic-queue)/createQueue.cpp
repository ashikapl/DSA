// Create Queue class without using STL
#include <iostream>
using namespace std;

class Queue
{
public:
    // Properties
    int *arr;
    int size;
    int front;
    int rear;

    // Constructor / ctor
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // Function
    void push(int data)
    {
        if (front == size)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear) // if Queue is empty
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        return rear - front;
    }
};

int main()
{
    Queue q(10);

    q.push(12);
    q.push(23);
    q.push(34);
    q.push(45);
    q.push(56);

    cout << "Size of Queue is: " << q.getSize() << endl;

    cout << "Front elemnt before pop: " << q.getFront() << endl;

    q.pop();

    cout << "Size of Queue is: " << q.getSize() << endl;

    cout << "Front element after pop: " << q.getFront() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}