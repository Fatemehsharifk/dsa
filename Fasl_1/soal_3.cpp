#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    // شرط پایه: اگر start به یا بیشتر از end رسید، عملیات تمام شده است
    if (start >= end) {
        return;
    }

    // جابجایی عناصر
    swap(arr[start], arr[end]);

    // فراخوانی بازگشتی برای زیرآرایه
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array:  ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // معکوس کردن آرایه
    reverseArray(arr, 0, n - 1);

    // چاپ آرایه معکوس شده
    cout << "Reverse array\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}