#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

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

        Node* node = new Node();
        node->next = nullptr;
        node->data = a;

        if (i == 1) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    Node* cur = head;
    int maxValue = head->data;

    while (cur != nullptr) {
        if (cur->data > maxValue) {
            maxValue = cur->data;
        }
        cur = cur->next;
    }

    while (head != nullptr && head->data == maxValue) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        if (cur->next->data == maxValue) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        } else {
            cur = cur->next;
        }
    }

    cout << "List after deleting maximum: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
