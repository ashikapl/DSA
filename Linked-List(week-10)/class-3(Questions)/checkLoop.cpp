// Check loop is present or not // find starting point of loop and also remove loop of linked list
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// check Loop is present or not
bool checkForLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// Find the starting point of loop
Node *startingPointLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            slow = head;
            break;
        }
    }

    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

// Remove loop from linked list
// Node *removeLoop(Node *&head)
// {
//     if (head == NULL)
//     {
//         cout << "LL is empty" << endl;
//         return NULL;
//     }

//     Node *slow = head;
//     Node *fast = head;

//     while (fast != NULL)
//     {
//         fast = fast->next;
//         if (fast != NULL)
//         {
//             fast = fast->next;
//             slow = slow->next;
//         }
//         if (fast == slow)
//         {
//             slow = head;
//             break;
//         }
//     }

//     Node *prev = fast;
//     while (slow != fast)
//     {
//         prev = fast;
//         fast = fast->next;
//         slow = slow->next;
//     }
//     prev->next = NULL;

//     return slow;
// }

// correct code to remove loop from linked list
void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes
    if (head == NULL)
    {
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }

    if (fast == NULL || fast->next == NULL)
    {
        return;
    }

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    while (slow->next != fast)
    {
        slow = slow->next;
    }
    slow->next = NULL;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fifth;

    cout << "Loop is present or not:-> " << checkForLoop(head) << endl;
    cout << "Starting Point of Loop is:-> " << startingPointLoop(head)->data << endl;
    removeLoop(head);
    print(head);
    cout << "Loop is present or not:-> " << checkForLoop(head) << endl;

    return 0;
}