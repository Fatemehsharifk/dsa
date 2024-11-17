#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[cap];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int data) {
        if (size == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = data;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};



class Stack {
private:
    Queue* q1;
    Queue* q2;

public:
    Stack(int capacity) {
        q1 = new Queue(capacity);
        q2 = new Queue(capacity);
    }

    ~Stack() {
        delete q1;
        delete q2;
    }

    void push(int data) {
        q2->enqueue(data);
        while (!q1->isEmpty()) {
            q2->enqueue(q1->front());
            q1->dequeue();
        }
        Queue* temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1->isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        q1->dequeue();
    }

    int top() {
        if (q1->isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1->front();
    }

    bool isEmpty() {
        return q1->isEmpty();
    }
};


int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    Stack s(capacity);

    int choice, value;
    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Check if Empty\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top: " << s.top() << endl;
                break;
            case 4:
                cout << "Stack empty: " << (s.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

