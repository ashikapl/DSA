#include <iostream>

// Definition for a ListNode.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    ListNode *slow = head, *fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}

// Utility function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original Linked List: ";
    printList(head);

    head = deleteMiddle(head);

    std::cout << "Linked List after deleting middle node: ";
    printList(head);

    return 0;
}
