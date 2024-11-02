#include <iostream>
#include <vector>

using namespace std;

// تابع برای چاپ n سطر اول مثلث خیام پاسکال
void khayampascal(int n) {
    vector<vector<int>> triangle(n); // ایجاد یک وکتور دوبعدی برای مثلث

    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1); // تنظیم اندازه هر سطر

        triangle[i][0] = 1; // اولین عنصر هر سطر 1 است
        triangle[i][i] = 1; // آخرین عنصر هر سطر 1 است

        // محاسبه عناصر وسطی
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // چاپ مثلث
    for (int i = 0; i < n; i++) {
        // چاپ فاصله برای تراز کردن مثلث
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "تعداد سطرهای مثلث خیام پاسکال را وارد کنید: ";
    cin >> n;

    khayampascal(n);

    return 0;

} 