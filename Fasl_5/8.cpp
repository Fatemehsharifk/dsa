#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// جهت‌های مجاز حرکت (شمال، جنوب، شرق، غرب و جهت‌های قطری)
int directions[8][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}, // شمال، جنوب، غرب، شرق
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1} // شمال غربی، شمال شرقی، جنوب غربی، جنوب شرقی
};

// تابعی برای بررسی صحت حرکت به خانه (x, y)
bool isValid(int x, int y, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y];
}

// تابع برای پیدا کردن مسیر از بالا چپ به پایین راست
bool findPath(int n, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    stack<pair<int, int>> s;
    vector<pair<int, int>> path;
    
    // شروع از خانه (0, 0)
    s.push({0, 0});
    visited[0][0] = true;
    
    while (!s.empty()) {
        int x = s.top().first;
        int y = s.top().second;
        path.push_back({x, y});
        s.pop();
        
        // اگر به مقصد رسیدیم
        if (x == n - 1 && y == n - 1) {
            // چاپ مسیر
            for (auto& p : path) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
            return true;
        }
        
        // بررسی تمام جهات مجاز حرکت
        for (int i = 0; i < 8; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            
            if (isValid(newX, newY, n, grid, visited)) {
                visited[newX][newY] = true;
                s.push({newX, newY});
            }
        }
    }
    
    // در صورت عدم یافتن مسیر
    return false;
}

int main() {
    int n;
    cout << "Enter the size of the grid (n x n): ";
    cin >> n;
    
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    cout << "Enter the grid (0 for empty space, 1 for obstacle):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    if (!findPath(n, grid, visited)) {
        cout << "No path found!" << endl;
    }
    
    return 0;
}
