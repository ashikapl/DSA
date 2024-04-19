#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q) {
    
    if(q.empty())
    {
        return;
    }
    
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

int main() {
    // Create a queue and populate it
    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    
    // Display original queue
    cout << "Original queue: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
    
    // Repopulate the queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    
    // Reverse the queue
    reverseQueue(myQueue);
    
    // Display reversed queue
    cout << "Reversed queue: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    return 0;
}
