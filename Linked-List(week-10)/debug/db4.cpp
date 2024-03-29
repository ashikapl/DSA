#include <iostream>

// Definition for a Node.
struct Node
{
    int data;
    Node *next;
    Node(int _data) : data(_data), next(nullptr) {}
};

void rotate(Node *&head, int k)
{
    if (k == 0)
        return;

    Node *current = head;

    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        return;
    }

    Node *kthNode = current;
    while (current->next != NULL)
        current = current->next;

    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
}

// Utility function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original Linked List: ";
    printList(head);

    int k = 2; // Rotate by 2 positions

    rotate(head, k);

    std::cout << "Linked List after rotating by " << k << " positions: ";
    printList(head);

    return 0;
}
