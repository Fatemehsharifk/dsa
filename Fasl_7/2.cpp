#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr) {}
};

Node* mergeSortedLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* mergedHead = nullptr;
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    Node* current = mergedHead;
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if (head1) {
        current->next = head1;
    } else {
        current->next = head2;
    }

    return mergedHead;
}

int main() {
    int n, m;
    cout << "Enter the number of numbers in the first sorted list: ";
    cin >> n;
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    for (int i = 1; i <= n; i++) {
        int a;
        cout << "Enter the number (" << i << ") : ";
        cin >> a;

        Node* node = new Node(a);

        if (i == 1) {
            head1 = node;
            tail1 = node;
        } else {
            tail1->next = node;
            tail1 = node;
        }
    }

    cout << "Enter the number of numbers in the second sorted list: ";
    cin >> m;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;
    for (int i = 1; i <= m; i++) {
        int a;
        cout << "Enter the number (" << i << ") : ";
        cin >> a;

        Node* node = new Node(a);

        if (i == 1) {
            head2 = node;
            tail2 = node;
        } else {
            tail2->next = node;
            tail2 = node;
        }
    }

    Node* mergedHead = mergeSortedLists(head1, head2);

    Node* cur = mergedHead;
    cout << "Merged list: ";
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    while (mergedHead != nullptr) {
        Node* temp = mergedHead;
        mergedHead = mergedHead->next;
        delete temp;
    }

    return 0;
}
