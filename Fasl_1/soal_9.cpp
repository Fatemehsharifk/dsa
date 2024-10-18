 #include <iostream>

using namespace std;

// تابعی برای محاسبه فاکتوریل به صورت بازگشتی
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // فاکتوریل 0 و 1 برابر 1 است
    }
    return n * factorial(n - 1); // فاکتوریل n برابر n * (n-1)!
}

// تابعی برای محاسبه مجموع فاکتوریل‌ها به صورت بازگشتی
int sumOfFactorials(int n) {
    if (n == 0) {
        return 0; // مجموع فاکتوریل‌ها تا 0 برابر 0 است
    }
    return factorial(n) + sumOfFactorials(n - 1); // جمع فاکتوریل n و مجموع فاکتوریل‌های قبل
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = sumOfFactorials(n);
    cout << "The sum of the first " << n << " factorials is: " << result << endl;

    return 0;
}