#include <iostream>
using namespace std;

void printArray(int arr[][100], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " "; // چاپ هر عنصر
        }
        cout << endl; // خط جدید برای هر ردیف
    }
}


void changeValue (int arr[][100], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // عناصر روی قطر اصلی
            if (i == j) {
                arr[i][j] += 1; // افزایش یک واحد
            }
            // عناصر روی قطر فرعی
            if (i + j == n - 1) {
                arr[i][j] -= 1; // کاهش یک واحد
            }
            // عناصر بالای قطر اصلی و فرعی
            if (i < j && i + j < n - 1) {
                arr[i][j] += 2; // افزایش دو واحد
            }
            // عناصر زیر قطر اصلی و فرعی
            if (i > j && i + j > n - 1) {
                arr[i][j] -= 2; // کاهش دو واحد
            } 
            // عناصر سمت چپ قطر اصلی و فرعی
            if (j < i && j + i < n - 1) {
                arr[i][j] += 3; // افزایش سه واحد
            }
            // عناصر سمت راست قطر اصلی و فرعی
            if (j > i && j + i > n - 1) {
                arr[i][j] -= 3; // کاهش سه واحد
            }
        }
    }

    // چاپ آرایه
    cout << "The array is:" << endl;
    printArray(arr, n);
}







int main() {
    const int MAX_SIZE = 100; // حداکثر اندازه آرایه
    int arr[MAX_SIZE][MAX_SIZE]; // تعریف آرایه دو بعدی
    int n;

    cout << "Enter the size of the array (n): ";
    cin >> n;
   
    // مقداردهی به آرایه
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<"Element ["<<i+1<<"]["<<j+1<<"]:";
            cin >> arr[i][j]; // گرفتن ورودی از کاربر
        }
    }
    changeValue(arr,n);

    

    return 0;
}