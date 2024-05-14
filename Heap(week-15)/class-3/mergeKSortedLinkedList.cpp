// merge k sorted Linked list into a singly sorted linked list
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

Node * mergeKLists(Node *arr[], int K)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;
        
    // insert k elements in minheap
    for(int i = 0; i < K; i++)
    {
        if(arr[i] != NULL)
        {
            minHeap.push(arr[i]);
        }
    }
        
    Node* head = NULL;
    Node* tail = NULL;
        
    // insert the remain next elements
    while(!minHeap.empty())
    {
        Node* temp = minHeap.top();
        minHeap.pop();
            
        if(head == NULL) // means first element
        {
            head = temp;
            tail = temp;
            if(tail->next != NULL)
            {
                minHeap.push(tail->next);
            }
        }
        else
        {
            tail->next = temp;
            tail = temp;
            if(tail->next != NULL)
            {
                minHeap.push(tail->next);
            }
        }
    }
        
    return head;
}

int main() {
    int K = 3; // Number of linked lists
    Node* arr[K];

    // Creating first linked list: 1 -> 4 -> 5
    arr[0] = new Node(1);
    arr[0]->next = new Node(4);
    arr[0]->next->next = new Node(5);

    // Creating second linked list: 1 -> 3 -> 4
    arr[1] = new Node(1);
    arr[1]->next = new Node(3);
    arr[1]->next->next = new Node(4);

    // Creating third linked list: 2 -> 6
    arr[2] = new Node(2);
    arr[2]->next = new Node(6);

    // Merge all lists
    Node* result = mergeKLists(arr, K);

    // Print merged linked list
    while(result != NULL) {
        std::cout << result->data << " ";
        result = result->next;
    }

    // Free allocated memory
    for (int i = 0; i < K; ++i) {
        while (arr[i] != NULL) {
            Node* temp = arr[i];
            arr[i] = arr[i]->next;
            delete temp;
        }
    }

    return 0;
}
