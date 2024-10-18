#include <iostream>

#include <vector>
using namespace std;

#define N 8 // اندازه صفحه شطرنج

// تابعی برای بررسی اینکه آیا وزیری در موقعیت (row, col) می‌تواند قرار گیرد یا خیر
bool isSafe(const vector<int>& board, int row, int col) {
    // بررسی ستون
    for (int i = 0; i < row; i++) {
        if (board[i] == col || 
            board[i] - i == col - row || 
            board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

// تابع بازگشتی برای قرار دادن وزرا
void placeQueens(vector<int>& board, int row) {
    if (row == N) {
       
        
        // اگر همه وزرا قرار گرفته‌اند، وضعیت فعلی را چاپ کنید
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j) {
                    cout << " Q "; // وزیری که قرار گرفته
                } else {
                    cout << " . "; // فضای خالی
                }
            }
            cout << endl;
        }
        cout <<endl; // فاصله بین حالت‌ها
        return;
    }

    // تلاش برای قرار دادن وزیر در هر ستون از ردیف فعلی
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // قرار دادن وزیر
            placeQueens(board, row + 1); // فراخوانی برای ردیف بعدی
            // board[row] = -1; // در اینجا نیازی به بازگشت نیست چون ما فقط مقدار را تغییر می‌دهیم
        }
    }
}

int main() {
    vector<int> board(N, -1); // آرایه برای نگهداری موقعیت وزرا
    placeQueens(board, 0); // شروع از ردیف اول
    return 0;
}

	
