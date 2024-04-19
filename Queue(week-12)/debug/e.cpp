#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x) {
        q2.push(x); // Push the new element to q2
        while (!q1.empty()) { // Move all elements from q1 to q2
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2); // Swap q1 and q2
    }

    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl;
    cout << "Popping: " << stack.pop() << endl;
    cout << "Top element after popping: " << stack.top() << endl;
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;

    return 0;
}
