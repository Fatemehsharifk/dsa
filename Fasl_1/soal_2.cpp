#include <iostream>
using namespace std;


double calculateSum(int arr[], int n) {
    //  اگر تعداد عناصر صفر باشد، مجموع برابر با صفر است
    if (n == 0) {
        return 0;
    }
    // جمع کردن آخرین عنصر با مجموع باقی‌مانده عناصر
    return arr[n - 1] + calculateSum(arr, n - 1);
}

double calculateAverage(int arr[], int n) {
    if (n == 0) {
        cout<<"Array size must be greater than zero";
    }
    double sum = calculateSum(arr, n);
    return sum / n; // محاسبه میانگین
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        std::cerr << "The number of elements must be greater than zero." <<endl;
        return 1;
    }

    int* arr = new int[n]; // ایجاد آرایه دینامیک

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    
        double average = calculateAverage(arr, n);
        cout << "The average of the array is: " << average << std::endl;

    delete[] arr; // آزادسازی حافظه
    return 0;
}