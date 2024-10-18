#include <iostream>
using namespace std;


int findMax(int arr[], int n) {
    // پایه بازگشتی: اگر آرایه تنها یک عنصر داشته باشد
    if (n == 1)
        return arr[0];

    // پیدا کردن ماکسیمم در بقیه آرایه
    int maxInRest = findMax(arr, n - 1);

    // مقایسه عنصر آخر با ماکسیمم بقیه آرایه
    return (arr[n - 1] > maxInRest) ? arr[n - 1] : maxInRest;
}


int main() {
    int n;
    cout << "Enter the number of elements in the array:  ";
    cin >> n;
        if (n == 0) {
        return 0;
    }

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Maximum array:  " << findMax(arr, n) << endl;
    return 0;
}