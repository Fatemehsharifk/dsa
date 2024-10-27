#include <iostream>
using namespace std;

long long combination(int n, int r) {
    int result;
    int* a = new int[n-r+1];
    a[0] =1;

    if (r > n) return 0; // اگر r بزرگتر از n باشد، ترکیب صفر است
    if (r == 0 || r == n) return 1; // C(n, 0) و C(n, n) برابر 1 است



        for (int i = 1; i < n-r+1 ; i++) {
            a[i] =(a[i-1] * (r+i))/i;
        }

    result = a[n-r];
    delete[] a;
    return result;
}

int main() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    long long result = combination(n, r);
    cout << "C(" << n << ", " << r << ") = " << result << endl;

    return 0;

} 