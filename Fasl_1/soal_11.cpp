 #include <iostream>

#include <vector>

using namespace std;
void breakCoin(int n, const vector<int>& coins, vector<int>& currentCombination) {
    // اگر مقدار سکه به صفر رسید، ترکیب فعلی را چاپ می‌کنیم
    if (n == 0) {
        for (int coin : currentCombination) {
            cout << coin << " ";
        }
        cout << endl;
        return;
    }

    // اگر مقدار سکه منفی شد، هیچ کاری نمی‌کنیم
    if (n < 0) {
        return;
    }

    // برای هر نوع سکه، تابع بازگشتی را فراخوانی می‌کنیم
    for (int coin : coins) {
        currentCombination.push_back(coin); // اضافه کردن سکه به ترکیب فعلی
        breakCoin(n - coin, coins, currentCombination); // فراخوانی بازگشتی
        currentCombination.pop_back(); // حذف سکه از ترکیب فعلی
    }
}

int main() {
    vector<int> coins = {2, 5, 10}; // تعریف سکه‌ها
    int n; // مقدار سکه n ریالی

    cout << "Enter the value of the coin (n): ";
    cin >> n; // دریافت مقدار سکه از کاربر

    vector<int> currentCombination; // لیست ترکیب فعلی

    breakCoin(n, coins, currentCombination); // فراخوانی تابع

    return 0;
}