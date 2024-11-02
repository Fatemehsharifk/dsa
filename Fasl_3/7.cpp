#include <iostream>

using namespace std;

bool isTranspose(int a[][50], int b[][50], int n) {
    // بررسی ابعاد و مقادیر
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // بررسی اینکه آیا عنصر i,j در a برابر با عنصر j,i در b است
            if (a[i][j] != b[j][i]) {
                return false; // اگر نابرابر باشد، false برمی‌گرداند
            }
        }
    }
    return true; // اگر همه مقادیر برابر بودند، true برمی‌گرداند
}

int main() {
    int A[50][50];
    int B[50][50];
    int n;

    cout << "Enter the number of rows of the matrix a and b: ";
    cin >> n;

    cout << "Enter the elements of matrix a:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of matrix b:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    if (isTranspose(A, B, n)) {
        cout << "a and b are transposes of each other." << endl;
    } else {
        cout << "a and b are not transposes of each other." << endl;
    }

    return 0;

} 