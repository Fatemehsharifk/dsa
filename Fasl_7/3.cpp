#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* pre;
    Node(int value): data(value), next(nullptr), pre(nullptr) {}
};

class PriorityQueue {
public:
    PriorityQueue(): head(nullptr), tail(nullptr) {}

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }

    int dequeue() {
        if (!head) {
            throw runtime_error("Queue is empty");
        }
        
        Node* minNode = head;
        Node* current = head;
        while (current) {
            if (current->data < minNode->data) {
                minNode = current;
            }
            current = current->next;
        }

        if (minNode->pre) {
            minNode->pre->next = minNode->next;
        } else {
            head = minNode->next;
        }

        if (minNode->next) {
            minNode->next->pre = minNode->pre;
        } else {
            tail = minNode->pre;
        }

        int minData = minNode->data;
        delete minNode;
        return minData;
    }

    bool isEmpty() {
        return !head;
    }

    ~PriorityQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    PriorityQueue pq;
    
    for (int i = 0; i < n; i++) {
        int element;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> element;
        pq.enqueue(element);
    }
    
    cout << "Sorted elements: ";
    while (!pq.isEmpty()) {
        cout << pq.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
