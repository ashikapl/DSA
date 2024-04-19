#include<iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T d) : data(d), next(nullptr) {}
};

template<typename T>
class Queue {
    int capacity;
    int size;
    Node<T>* head;
    Node<T>* tail;
public :
    Queue() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    void enqueue(T data) {
        Node<T>* temp = new Node<T>(data);
        if(isEmpty()){
            head = temp;
        }
        else{
            tail->next = temp;
        }
        tail = temp;
        size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    T dequeue() {
        if(isEmpty()) {
            cerr << "Queue is empty!" << endl;
            exit(1); // Or handle error appropriately
        }
        T data = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;
    }
    
    T front() {
        if(isEmpty()) {
            cerr << "Queue is empty!" << endl;
            exit(1); // Or handle error appropriately
        }
        return head->data;
    }
};

int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Queue size after dequeue: " << q.getSize() << endl;
    cout << "Front element after dequeue: " << q.front() << endl;

    return 0;
}
