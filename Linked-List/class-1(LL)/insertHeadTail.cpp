// Insert at Head and Tail
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// insert a new node at left side of Linked list
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // check the node is Empty or not
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Non-Empty
        // Step:1 -> create a new Node
        Node *newNode = new Node(data);
        // Step:2 -> connect with head
        newNode->next = head;
        // Step:3 -> update head
        head = newNode;
    }
}

// insert a new node at right side of Linked list
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // check the node is Empty or not
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Non-empty
        //  Step:1 -> create a new Node
        Node *newNode = new Node(data);
        // Step:2 -> connect with tail
        tail->next = newNode;
        // Step:3 -> update tail
        tail = newNode;
    }
}

// print values
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // inserting head values
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);

    // inserting tail values
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);

    print(head);

    return 0;
}