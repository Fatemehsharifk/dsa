  #include <iostream>

using namespace std;

// تابعی برای محاسبه فاکتوریل به صورت بازگشتی
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // فاکتوریل 0 و 1 برابر 1 است
    }
    return n * factorial(n - 1); // فاکتوریل n برابر n * (n-1)!
}

// تابعی برای محاسبه مجموع سری به صورت بازگشتی
double sumOfSeries(int n) {
    if (n == 0) {
        return 0; // مجموع سری تا 0 برابر 0 است
    }
    return (1.0 / factorial(n)) + sumOfSeries(n - 1); // جمع جمله n و مجموع جملات قبل
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    double result = sumOfSeries(n);
    cout << "The sum of the series up to " << n << " is: " << result << endl;

    return 0;
}