#include <iostream>
using namespace std;


void decToBinary(int n) {
    // شرط پایه: اگر n برابر با 0 باشد، هیچ چیزی چاپ نمی‌کنیم
    if (n == 0) {
        return;
    }
    
    // ابتدا تابع را به صورت بازگشتی برای n/2 فراخوانی می‌کنیم
    decToBinary(n / 2);
    
    // سپس باقی‌مانده n را به دست آورده و چاپ می‌کنیم
    cout << (n % 2);
}

int main() {
    int number;
    cout << "please enter a number in base ten : ";
    cin >> number;

    cout << "base two: " << number <<endl  ;
    
    // اگر عدد 0 باشد، باید به طور خاص آن را چاپ کنیم
    if (number == 0) {
        cout << "0";
    } else {
        decToBinary(number);
    }
    
    cout << endl;
    return 0;

} 