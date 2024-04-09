// Create, Insertion, removal, size, front, emptyCheck using STL Of Queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Creation
    queue<int> q;

    // Insertion
    q.push(11);
    q.push(22);
    q.push(33);
    q.push(44);
    q.push(55);

    // size
    cout << "Size of Queue Before removal is: " << q.size() << endl;
    // Removal
    q.pop(); // first element is remove from queue(FIFO) order First in first out (11)

    cout << "Size of Queue After removal is: " << q.size() << endl;

    // front element
    cout << "Front element of Queue is: " << q.front() << endl;

    // back elment
    cout << "Back element of Queue is: " << q.back() << endl; // back means last element

    // empty Check
    if (q.empty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }

    return 0;
}