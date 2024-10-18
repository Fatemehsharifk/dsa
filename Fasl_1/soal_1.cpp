#include <iostream>
using namespace std;


int divide(int a,int b){
    if(b == 0){
        // Division by zero
        cout<<"Division by zero";
    }
    if (a < b) {
        return 0;
    }

    return 1 + divide(a - b ,b);

}


int main() {
    int a, b;
    cout << "Enter two integers (a and b): ";
    cin >> a >> b;

        int result = divide(a, b);
        cout << "The quotient of " << a << " divided by " << b << " is: " << result <<endl;

    

    return 0;
}


