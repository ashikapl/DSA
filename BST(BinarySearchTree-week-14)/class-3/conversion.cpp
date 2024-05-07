// Convert BST into a sorted Doubly Linked list
// Convert Sorted Linked-List into BST
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void lOT(Node *root) // Level Order Traversal (lOT)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node* BSTusingInorder(int inOrder[], int s, int e)
{
    // Base case
    if(s > e)
    {
        return NULL;
    }

    int mid = (s+e)/2;
    int element = inOrder[mid];
    Node* root = new Node(element);

    root->left = BSTusingInorder(inOrder,s,mid-1);
    root->right = BSTusingInorder(inOrder,mid+1,e);

    return root;
}

void convertIntoDoublyLL(Node* root, Node* &head)
{
    if(root == NULL)
    {
        return;
    }

    // right subtree Into LL
    convertIntoDoublyLL(root->right,head);

    // attach into root->right to head
    root->right = head;
    
    if(head != NULL)
    {
        head->left = root;
    }

    // Update head
    head = root;

    // left Subtree into LL
    convertIntoDoublyLL(root->left,head);
}

void printLL(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

Node* convertLinkedListIntoBST(Node* &head, int n)
{
    if(n <= 0 || head == NULL) return NULL;

    Node* leftSubtree = convertLinkedListIntoBST(head,n-1-n/2);

    Node* root = head;

    // attach left part into root
    root->left = leftSubtree;

    // update head
    head = head->right;
    
    // right subtree
    root->right = convertLinkedListIntoBST(head,n/2);

    return root;
}

int main()
{
    int inOrder[] = {1,2,3,4,5,6,7};
    int s = 0;
    int e = 6;

    Node* root = BSTusingInorder(inOrder,s,e);
    cout << "BST Using Inorder: " << endl;
    lOT(root);
    
    Node* head = NULL;
    convertIntoDoublyLL(root,head);
    cout << "Printing the Doubly Linked List: " << endl;
    printLL(head);

    Node* root1 = NULL;
    root1 = convertLinkedListIntoBST(head,8);
    cout << "Linked-list to BST: " << endl;
    lOT(root1);

    return 0;
}