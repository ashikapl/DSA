// Insert at any position in linked list
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

int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // At first Position
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // At last Position
    int len = findLength(head);
    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // At middle postion
    // Step:1 -> find previous and current node
    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }

    Node *curr = prev->next;

    // Step:2 -> create new node
    Node *newNode = new Node(data);

    // Step:2
    newNode->next = curr;

    // Step :3
    prev->next = newNode;
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

    print(head);
    cout << endl;

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    insertAtPosition(100, 4, head, tail);

    cout << "After inserting a node at given position" << endl;

    print(head);
    cout << endl;

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}