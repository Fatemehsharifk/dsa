 #include <iostream>

#include <string>
using namespace std;
bool isDuplicate(const std::string& s) {
    int n = s.length();

    // اگر طول رشته صفر باشد، تکراری است
    if (n == 0) return true;

    // بررسی تمام طول‌های ممکن برای r
    for (int len = 1; len <= n / 2; ++len) {
        // اگر n قابل تقسیم بر len باشد
        if (n % len == 0) {
            string r = s.substr(0, len);
            string repeated;

            // ساخت رشته تکراری
            for (int i = 0; i < n / len; ++i) {
                repeated += r;
            }

            // بررسی اینکه آیا رشته ساخته شده با رشته اصلی برابر است
            if (repeated == s) {
                // بررسی اینکه آیا حذف کاراکتر اول r هم تکراری است
                if (isDuplicate(r.substr(1))) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isDuplicate(input)) {
        cout << "The string is duplicate." << endl;
    } else {
        cout << "The string is not duplicate." << endl;
    }

    return 0;
}