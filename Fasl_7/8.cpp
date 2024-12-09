#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* pre;
    Node(int value): data(value), next(nullptr), pre(nullptr){}
};

void makeCircular(Node* head) {
    if (!head) return; 

    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = head; 
    head->pre = cur; 
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
            node->pre = tail;
            tail = node;
        }
    }

    makeCircular(head);

    Node* cur = head;
    
    for (int i = 0; i < count; i++) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\nhead->pre : " << (cur->pre)->data << endl;
    cur = cur->pre;
    cout << "Last node->next : " << (cur->next)->data << endl;

    Node* temp;
    for (int i = 0; i < count; i++) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
