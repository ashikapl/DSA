// Replace Zeroes , Ones and Twoes from Linked list
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

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void sortZeroesOnesAndTwos(Node *&head)
{
    // Step: 1 -> count Zeroes , Ones and Twoes
    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else if (temp->data == 2)
        {
            two++;
        }
        temp = temp->next;
    }

    temp = head;

    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (two--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

Node *sort2(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }

    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            // take out zero wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append zero node in zeroTail LL
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1)
        {
            // take out zero wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append zero node in zeroTail LL
            oneTail->next = temp;
            oneTail = temp;
        }
        else if (curr->data == 2)
        {
            // take out zero wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append zero node in zeroTail LL
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // all zero , one and two nodes are prepared
    // Now join them and remove extra node of (-1)

    // modify oneHead node
    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // modify twoHead node
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // Join list
    if (oneHead != NULL)
    {
        zeroTail->next = oneHead;
        if (twoHead != NULL)
        {
            oneTail->next = twoHead;
        }
    }
    else
    {
        if (twoHead != NULL)
        {
            zeroTail->next = twoHead;
        }
    }

    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // return head of modified node
    return zeroHead;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(0);
    Node *third = new Node(0);
    Node *fourth = new Node(0);
    Node *fifth = new Node(2);
    Node *sixth = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    cout << "Input LL: ";
    print(head);

    // sortZeroesOnesAndTwos(head);
    // print(head);

    // Node *temp = NULL;
    head = sort2(head);
    cout << "Output LL: ";
    print(head);

    return 0;
}