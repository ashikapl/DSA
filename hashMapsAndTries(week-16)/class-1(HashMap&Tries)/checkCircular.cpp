// Check the linked list is cirular or not (loop)
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

bool checkCircular(Node* head) {
    unordered_map<Node*, bool> visit;
    Node* temp = head;

    while(temp != NULL) {
        if(visit.find(temp) != visit.end()) {
            // Node already visited, so there is a loop
            return true;
        }
        // Mark this node as visited
        visit[temp] = true;
        temp = temp->next;
    }

    // No loop found
    return false;
}

int main() {
    // Create a test linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    // Creating a loop for testing
    head->next->next->next->next = head->next;

    if(checkCircular(head)) {
        cout << "The linked list is circular (contains a loop)." << endl;
    } else {
        cout << "The linked list is not circular (does not contain a loop)." << endl;
    }

    return 0;
}
