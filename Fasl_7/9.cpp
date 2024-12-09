#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value): data(value), next(nullptr) {}
    Node(const Node &node): data(node.data), next(nullptr) {}
};

void duplicateNodes(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        Node* newNode = new Node(*current); 
        newNode->next = current->next;      
        current->next = newNode;            
        current = newNode->next;            
    }
}

int main() {
    int count;
    cout << "Enter the number of numbers: ";
    cin >> count;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 1; i <= count; i++) {
        int a;
        cout << "Enter the number (" << i << ") : ";
        cin >> a;

        Node* node = new Node(a);

        if (i == 1) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    duplicateNodes(head);

    Node* cur = head;
    cout << "List after duplicating nodes: ";
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
