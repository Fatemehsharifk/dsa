#include <iostream>

#include <string>
#include <stack>
#include <cctype>

using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // فرض بر این است که b != 0
    }
    return 0;
}

int evaluateExpression(const string& expression, int x_value) {
    stack<int> values; // برای ذخیره مقادیر
    stack<char> ops;   // برای ذخیره عملگرها

    for (size_t i = 0; i < expression.length(); i++) {
        // اگر کاراکتر عدد باشد
        if (isdigit(expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--; // به کاراکتر قبلی برگرد
        }
        // اگر کاراکتر x باشد
        else if (expression[i] == 'x') {
            values.push(x_value);
        }
        // اگر کاراکتر عملگر باشد
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                int right = values.top(); values.pop();
                int left = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(left, right, op));
            }
            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        int right = values.top(); values.pop();
        int left = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(left, right, op));
    }

    return values.top();
}



int main() {
    string s;
    int x;

    cout << "Enter the expression (use 'x' for the variable): ";
    cin >> s;
    cout << "Enter the value of x: ";
    cin >> x;

    int result = evaluateExpression(s, x);
    cout << "The result is: " << result << endl;

    return 0;
}