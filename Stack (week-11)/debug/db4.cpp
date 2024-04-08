#include <iostream> // Include necessary headers

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack() : head(nullptr), size(0) {} // Constructor

    ~Stack()
    { // Destructor to prevent memory leaks
        while (!isEmpty())
        {
            pop();
        }
    }

    int getSize() const
    { // Member function to get the size of the stack
        return size;
    }

    bool isEmpty() const
    { // Member function to check if the stack is empty
        return head == nullptr;
    }

    void push(const T &element)
    { // Member function to push an element onto the stack
        Node<T> *temp = new Node<T>(element);
        temp->next = head;
        head = temp;
        size++;
    }

    T pop()
    { // Member function to pop an element from the stack
        if (isEmpty())
        {
            throw std::out_of_range("Stack is empty");
        }
        T data = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;
    }

    T top() const
    { // Member function to get the top element of the stack
        if (isEmpty())
        {
            throw std::out_of_range("Stack is empty");
        }
        return head->data;
    }
};

int main()
{
    // Example usage
    Stack<int> stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    std::cout << "Top element: " << stack.top() << std::endl;
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    while (!stack.isEmpty())
    {
        std::cout << "Popped element: " << stack.pop() << std::endl;
    }

    return 0;
}
