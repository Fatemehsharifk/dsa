#include <iostream>
using namespace std;

class TwoQueues {
private:
    int* arr;       // آرایه‌ی مشترک
    int capacity;   // ظرفیت کل آرایه
    int front1, rear1; // جلو و انتهای صف اول
    int front2, rear2; // جلو و انتهای صف دوم

public:
    // سازنده
    TwoQueues(int maxCapacity) {
        capacity = maxCapacity;
        arr = new int[capacity];
        front1 = -1;
        rear1 = -1;
        front2 = capacity;
        rear2 = capacity;
    }

    ~TwoQueues() {
        delete[] arr; // آزادسازی حافظه
    }

    // افزودن عنصر به صف اول
    void enqueue1(int value) {
        if (rear1 + 1 == rear2) {
            cout << "Overflow in Queue 1" << endl;
            return;
        }
        if (front1 == -1) front1 = 0;
        arr[++rear1] = value;
    }

    // افزودن عنصر به صف دوم
    void enqueue2(int value) {
        if (rear1 + 1 == rear2) {
            cout << "Overflow in Queue 2" << endl;
            return;
        }
        if (front2 == capacity) front2 = capacity - 1;
        arr[--rear2] = value;
    }

    // حذف عنصر از صف اول
    int dequeue1() {
        if (front1 == -1 || front1 > rear1) {
            cout << "Underflow in Queue 1" << endl;
            return -1;
        }
        int value = arr[front1++];
        if (front1 > rear1) { // صف خالی شد
            front1 = -1;
            rear1 = -1;
        }
        return value;
    }

    // حذف عنصر از صف دوم
    int dequeue2() {
        if (front2 == capacity || front2 < rear2) {
            cout << "Underflow in Queue 2" << endl;
            return -1;
        }
        int value = arr[front2--];
        if (front2 < rear2) { // صف خالی شد
            front2 = capacity;
            rear2 = capacity;
        }
        return value;
    }

    // نمایش وضعیت صف اول
    void displayQueue1() {
        if (front1 == -1) {
            cout << "Queue 1 is empty" << endl;
            return;
        }
        for (int i = front1; i <= rear1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // نمایش وضعیت صف دوم
    void displayQueue2() {
        if (front2 == capacity) {
            cout << "Queue 2 is empty" << endl;
            return;
        }
        for (int i = front2; i >= rear2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TwoQueues queues(100);

    queues.enqueue1(10);
    queues.enqueue1(20);
    queues.enqueue1(30);

    queues.enqueue2(100);
    queues.enqueue2(200);
    queues.enqueue2(300);

    cout << "Queue 1: ";
    queues.displayQueue1();

    cout << "Queue 2: ";
    queues.displayQueue2();

    queues.dequeue1();
    queues.dequeue2();

    cout << "After dequeuing one element from each queue:" << endl;
    cout << "Queue 1: ";
    queues.displayQueue1();

    cout << "Queue 2: ";
    queues.displayQueue2();

    return 0;
}
