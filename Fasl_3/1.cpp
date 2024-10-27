#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the position of Fibonacci number (n): ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    
    if (n == 0 || n==1 ) {
        cout << "Fibonacci number at position " << n << " is " << n << endl;
        return 0;
    }
    int *a = new int[n];
    a[0] =1;
    a[1] =1;
    
    for (int i = 2; i <= n; i++) {
        a[i] = a[i-1] + a[i-2];
    }

    cout << "Fibonacci number at position " << n << " is " << a[n-1] << "." << endl;

    delete[] a;
    return 0;

}