#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
        s2.pop();
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    int peek() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;
    
    // Push elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    
    // Pop and print elements from the queue
    cout << q.pop() << endl; // Output: 1
    cout << q.pop() << endl; // Output: 2
    
    // Peek at the front element of the queue
    cout << "Front element: " << q.peek() << endl; // Output: 3
    
    // Check if the queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: No
    
    // Pop the remaining element
    cout << q.pop() << endl; // Output: 3
    
    // Check if the queue is empty after popping all elements
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: Yes
    
    return 0;
}
