#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value): data(value), next(nullptr) {}
};

void bubbleSort(Node* head) {
    if (!head) return;

    bool swapped;
    Node* current;
    Node* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
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

    bubbleSort(head);

    Node* cur = head;
    cout << "Sorted list: ";
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
