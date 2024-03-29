#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *middle = middleNode(head);

    std::cout << "Middle node value: " << middle->val << std::endl;

    // Free memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
