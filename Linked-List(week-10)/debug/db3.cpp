#include <iostream>

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while (slow != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }

        return false;
    }
};

int main()
{
    // Create a sample linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (points back to 3)
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next; // Creating a cycle

    Solution solution;
    bool hasCycle = solution.hasCycle(head);

    if (hasCycle)
        std::cout << "The linked list has a cycle." << std::endl;
    else
        std::cout << "The linked list does not have a cycle." << std::endl;

    // Free memory
    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
