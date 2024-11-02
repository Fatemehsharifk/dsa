 #include <iostream>
#include <string>

using namespace std;

class bigNumber {
    int digit[1000] = {0}; 
    bool sign; 
    int size;

public:
    bigNumber();
    bigNumber(string);
    bigNumber(int);
    void shiftRight();
    void shiftLeft();
    void shiftRight(int);
    void shiftLeft(int);
    bigNumber add(const bigNumber&);
    bigNumber subtract(const bigNumber&);
    void print();
};

bigNumber::bigNumber() {
    size = 1;
    digit[999] = 0;
}

bigNumber::bigNumber(string bn) {
    size = bn.length();
    for (int i = 0; i < size; i++) {
        digit[999 - i] = bn[size - 1 - i] - '0'; 
    }
}

bigNumber::bigNumber(int a) {
    size = 0;
    while (a > 0) {
        digit[999 - size] = a % 10;
        a /= 10;
        size++;
    }
}

void bigNumber::shiftRight() {
    if (size > 1) {
        for (int i = 0; i < size - 1; i++) {
            digit[999 - i] = digit[999 - i - 1];
        }
        digit[999 - size + 1] = 0; 
        size--;
    }
}

void bigNumber::shiftLeft() {
    if (size < 1000) { 
        for (int i = size; i > 0; i--) {
            digit[1000 - i - 1] = digit[1000 - i]; 
        }
        digit[999] = 0; 
        size++;
    }
}

void bigNumber::shiftRight(int c) {
    if (size > c) { 
        for (int i = 0; i < size - c; i++) {
            digit[999 - i] = digit[999 - i - c];
        }
        for (int i = size - c; i < size; i++) {
            digit[999 - i] = 0;
        }
        size -= c;
    } else {
        size = 0; 
    }
}

void bigNumber::shiftLeft(int c) {
    if (size + c < 1000) { 
        for (int i = size; i > 0; i--) {
            digit[1000 - i - c] = digit[1000 - i]; 
        }
        for (int i = 0; i < c; i++) {
            digit[1000 - c + i] = 0;
        }
        size += c;
    }
}

bigNumber bigNumber::add(const bigNumber& other) {
    bigNumber result;
    int carry = 0;

    for (int i = 1; i <= max(size, other.size) || carry; i++) {
        int m = carry;
        if (i <= size) m += digit[1000 - i];
        if (i <= other.size) m += other.digit[1000 - i];

        result.digit[1000 - i] = m % 10;
        carry = m / 10;
        result.size = max(result.size, i);
        if (carry) result.size++;
    }

    return result;
}

bigNumber bigNumber::subtract(const bigNumber& other) {
    bigNumber result;
    int borrow = 0;

    for (int i = 0; i < size; i++) {
        int sub = digit[999 - i] - borrow;
        if (i < other.size) sub -= other.digit[999 - i];

        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.digit[999 - i] = sub;
    }

    result.size = size;

  
    while (result.size > 1 && result.digit[1000 - result.size] == 0) {
        result.size--;
    }

    return result;
}

void bigNumber::print() {
    for (int i = 1000 - size; i < 1000; i++) {
        cout << digit[i];
    }
    cout << endl;
}

int main() {
    int n, k, s, h;

    cout << "Enter first integer: ";
    cin >> n;
    cout << "Enter second integer: ";
    cin >> k;

    bigNumber num1(n);
    bigNumber num2(k);

 
    bigNumber r_add = num1.add(num2);
    cout << "Sum: ";
    r_add.print(); 
 
    bigNumber r_subtract = num1.subtract(num2);
    cout << "Difference: ";
    r_subtract.print(); 
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1; 
    cout << "Enter second string: ";
    cin >> str2; 

    bigNumber num3(str1);
    bigNumber num4(str2);

 
    bigNumber s_add = num3.add(num4);
    cout << "Sum: ";
    s_add.print(); 

    
    bigNumber s_subtract = num3.subtract(num4);
    cout << "Difference: ";
    s_subtract.print(); 

   
    num3.shiftRight();
    cout << "First number after shifting right by 1: ";
    num3.print();

   
    num3.shiftLeft();
    cout << "First number after shifting left by 1: ";
    num3.print();

    cout << "Enter number of positions to shift right: ";
    cin >> s;

    num3.shiftRight(s);
    cout << "First number after shifting right by " << s << ": ";
    num3.print();

    cout << "Enter number of positions to shift left: ";
    cin >> h;

    num4.shiftLeft(h);
    cout << "Second number after shifting left by " << h << ": ";
    num4.print();

    return 0;
}