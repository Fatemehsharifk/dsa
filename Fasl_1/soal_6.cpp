#include <iostream>


int multiply(int a, int b) {
    // اگر b برابر صفر باشد، حاصل‌ضرب برابر صفر است
    if (b == 0) {
        return 0;
    }
    // اگر b منفی باشد، علامت را تغییر می‌دهیم
    if (b < 0) {
        return -multiply(a, -b);
    }
    // در غیر این صورت، a را به حاصل‌ضرب (a * (b-1)) اضافه می‌کنیم
    return a + multiply(a, b - 1);
}

int main() {
    int a, b;
    
    std::cout << "Enter two integers (a and b): ";
    std::cin >> a >> b;

    int result = multiply(a, b);
    std::cout << "The product of " << a << " and " << b << " is: " << result << std::endl;

    return 0;
}