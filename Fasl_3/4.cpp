#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

class BigNumber {
private:
    vector<int> digits; // برای ذخیره ارقام

public:
    // سازنده پیش‌فرض
    BigNumber() {
        digits.push_back(1); // شروع با 1
    }

    // تابع برای ضرب BigNumber با یک عدد صحیح
    void multiply(int num) {
        int carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int product = digits[i] * num + carry;
            digits[i] = product % 10; // حفظ رقم
            carry = product / 10; // محاسبه carry
        }
        while (carry) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    // تابع برای محاسبه فاکتوریل
    static BigNumber factorial(int n) {
        BigNumber result;
        for (int i = 2; i <= n; ++i) {
            result.multiply(i);
        }
        return result;
    }

    // تابع برای نمایش عدد
    void print() const {
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            cout << *it;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    BigNumber result = BigNumber::factorial(n);
    cout << "Factorial of " << n << " is: ";
    result.print();

    return 0;
}

