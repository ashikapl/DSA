// Insert at position in doubly linked-list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node *head)
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

void insertAthead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);

        newNode->next = head;
        head->prev = newNode;

        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);

        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        cout << "Linked-List is empty" << endl;
        return;
    }

    if (position == 1)
    {
        insertAthead(head, tail, data);
        return;
    }

    int len = getLength(head);

    if (position > len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // insert at middle
    int i = 1;
    Node *prevNode = head;
    while (i < position - 1)
    {
        prevNode = prevNode->next;
        i++;
    }

    Node *curr = prevNode->next;

    Node *newNode = new Node(data);

    newNode->prev = prevNode;
    prevNode->next = newNode;
    newNode->next = curr;
    curr->prev = newNode;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);
    cout << endl;

    int length = getLength(first);
    cout << "Length of Node:-> " << length << endl;

    insertAthead(head, tail, 12);
    insertAtTail(head, tail, 100);
    insertAtPosition(head, tail, 204, 4);
    print(head);

    return 0;
}