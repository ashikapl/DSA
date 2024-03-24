// Check whether the Linked-List is a valid Palindrome or not
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

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool checkPalindromeLL(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return true;
    }
    if (head->next == NULL)
    {
        // only single element
        return true;
    }

    // Step: 1 - find middle node
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // slow pointer is pointing to middle node

    // Step:2 - reverse the elements after middle node
    Node *reverseKaHead = reverse(slow->next);

    // join the reverse elements
    slow->next = reverseKaHead;

    // Step:3 - compare
    Node *temp1 = head;
    Node *temp2 = slow->next;

    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return true;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(20);
    Node *fifth = new Node(10);
    // Node *sixth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    // sixth->next = NULL;

    bool isPalindrome = checkPalindromeLL(head);

    if (isPalindrome)
    {
        cout << "LL is a valid Palindrome" << endl;
    }
    else
    {
        cout << "LL is not a Palindrome" << endl;
    }

    return 0;
}