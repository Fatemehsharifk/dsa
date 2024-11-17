#include <iostream>
#include <stack>

using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stack1; 
    stack<int> stack2; 

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cout << "Queue is empty!" << endl;
                return -1; 
            }

            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int top = stack2.top();
        stack2.pop();
        return top;
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    int front() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cout << "Queue is empty!" << endl;
                return -1; 
            }

            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();
    }
};

int main() {
    QueueUsingTwoStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeue: " << q.dequeue() << endl; // 10
    cout << "Dequeue: " << q.dequeue() << endl; // 20

    cout << "Front: " << q.front() << endl; // 30

    cout << "Dequeue: " << q.dequeue() << endl; // 30

    cout << "Is Queue Empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
