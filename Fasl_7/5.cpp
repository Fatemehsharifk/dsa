#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr){}
};

class Stack
{
private:
    Node* head;  
public:
    Stack(): head(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;
        } else {
            int number = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            return number;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        } else {
            return head->data;
        }
    }

    void print() {
        cout << "Stack: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    int choice, value;
    do {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Is Empty";
        cout << "\n5. Print";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the number: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            cout << "Top element is: " << stack.peek() << endl;
            break;
        case 4:
            cout << "Stack " << (stack.isEmpty() ? "is empty." : "is not empty.") << endl;
            break;
        case 5:
            stack.print();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
