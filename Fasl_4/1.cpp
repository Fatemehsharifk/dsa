#include <iostream>
#include <stdexcept>

using namespace std;

class Queue {
private:
    int* a;        // آرایه‌ای پویا برای نگهداری عناصر
    int* front;    // اشاره‌گر به اولین عنصر صف
    int* back;     // اشاره‌گر به آخرین عنصر صف
    int size;      // تعداد عناصر موجود در صف
    int capacity;  // حداکثر ظرفیت صف

public:
    // سازنده با ظرفیت مشخص
    Queue(int capacity) {
        this->capacity = capacity;
        a = new int[capacity];
        front = nullptr; // در ابتدا صف خالی است
        back = nullptr;  // در ابتدا صف خالی است
        size = 0;        // اندازه صف صفر است
    }

    // سازنده پیش‌فرض با ظرفیت 100
    Queue() : Queue(100) {}

    // اضافه کردن عنصر به صف
    void enqueue(int element) {
        if (size < capacity) {
            if (size == 0) {
                // اولین عنصر در صف
                front = back = a;
                *back = element;
            } else {
                // حرکت اشاره‌گر به موقعیت بعدی (چرخشی)
                back = (back == a + capacity - 1) ? a : back + 1;
                *back = element;
            }
            size++;
        } else {
            throw overflow_error("The queue is full");
        }
    }

    // حذف و بازگرداندن کوچک‌ترین عنصر از صف
    int dequeue() {
        if (size > 0) {
            // پیدا کردن کوچک‌ترین عنصر
            int* minPtr = front;
            int* current = front;

            for (int i = 0; i < size; i++) {
                if (*current < *minPtr) {
                    minPtr = current;
                }
                // حرکت به خانه بعدی به صورت چرخشی
                current = (current == a + capacity - 1) ? a : current + 1;
            }

            // ذخیره کوچک‌ترین عنصر برای بازگرداندن
            int result = *minPtr;

            // جابه‌جا کردن عناصر بعد از حذف کوچک‌ترین عنصر
            current = minPtr;
            for (int i = 0; i < size - 1; i++) {
                int* next = (current == a + capacity - 1) ? a : current + 1;
                *current = *next;
                current = next;
            }

            // کاهش اندازه و به‌روزرسانی اشاره‌گر back
            back = (back == a) ? a + capacity - 1 : back - 1;
            size--;

            // اگر صف خالی شود، اشاره‌گرها را ریست می‌کنیم
            if (size == 0) {
                front = back = nullptr;
            }

            return result;
        } else {
            throw out_of_range("The queue is empty");
        }
    }

    // بازگرداندن تعداد عناصر موجود در صف
    int getSize() const {
        return size;
    }

    // نابودگر برای آزاد کردن حافظه
    ~Queue() {
        delete[] a;
    }
};

int main() {
    // ایجاد صف با ظرفیت پیش‌فرض
    Queue q;

    // اضافه کردن عناصر به صف
    q.enqueue(10);
    q.enqueue(5);
    q.enqueue(20);
    q.enqueue(1);

    // حذف و چاپ عناصر به ترتیب اولویت
    cout << "Queue elements in order of priority: ";
    while (q.getSize() > 0) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
