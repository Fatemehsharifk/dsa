#include <iostream>
using namespace std;

int gcd(int a,int b){
    if (b == 0)return a;
    return gcd(b,a%b);

}

int main() {
    int a,b;
    cout << "Enter two number :";
    cin >> a >> b;

    int result = gcd(a,b);
    cout<<"GCD is :"<<result<<endl;

}



