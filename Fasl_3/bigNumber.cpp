
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

class bigNumber {
    string str; 
    bool sign; 
    int size;

public:
    bigNumber();
    bigNumber(string);
  
    void shiftRight();
    void shiftLeft();
    void shiftRight(int);
    void shiftLeft(int);
    bigNumber add(bigNumber);
    bigNumber subtract(bigNumber);
    bigNumber multiply(bigNumber);
   // bigNumber divide(bigNumber);
    bigNumber factorial(int);
    bigNumber power(int);
    bigNumber karatsuba(bigNumber);
    string removeLeadingZeros(const string& );
    void print();
};


bigNumber::bigNumber() {
    str = "";
    size = 1;
    sign = false; 
}

bigNumber::bigNumber(string bn) {
    if(bn[0] == '-'){
        sign = true;
        str = bn.substr(1);
    }else if(bn[0] == '+'){
        sign = false;
        str = bn.substr(1);
    }else{
        sign = false;
        str = bn;
    }
    size = str.size();
}



void bigNumber::shiftRight() {
    if(str != ""){
        str.pop_back();
        size--;
        }
}


void bigNumber::shiftLeft() {
        str += '0';
        size++;
        }

void bigNumber::shiftRight(int c) {
    if (size > c) { 
        for (int i = 0; i < c; i++) {
            str.pop_back();  
        }
        size -= c;  
    } else {
        str = "";
        size = 0;
        if (sign){
            sign=false;
        }

        
    }
}


void bigNumber::shiftLeft(int c) {
        for (int i = 0; i < c; i++) {
            str += '0';
        }
        size += c;
    }


bigNumber bigNumber::add(bigNumber other) {
       if(other.sign != sign){
        other.sign = sign;
       return this->subtract(other);

    }
    int maxSize = max(size, other.size);
    bigNumber result;
    result.size = maxSize;  

    int carry = 0; 
    for (int i = 0; i < maxSize || carry; i++) {
        int sum = carry; 
        if (i < size) 
            sum += str[size - 1 - i] - '0';  
        
        if (i < other.size) 
        sum += other.str[other.size - 1 - i] - '0';   
        carry = sum / 10;
        result.str = char((sum % 10) + '0')+result.str;
    }
    result.sign = sign; 
    return result;
}


bigNumber bigNumber::subtract(bigNumber other) {
    bigNumber result;

    // اگر علامت‌ها متفاوت باشند، تفریق به جمع تبدیل می‌شود
    if (other.sign != sign) {
        other.sign = sign;
        return this->add(other);
    }

    bool thisIsGreater = false;
    if (size > other.size) {
        thisIsGreater = true;
    } else if (size == other.size) {
        int strSize = str.size();
        for (int i = 0; i < strSize; ++i) {
            if (str[i] > other.str[i]) {
                thisIsGreater = true;
                break;
            } else if (str[i] < other.str[i]) {
                thisIsGreater = false;
                break;
            }
        }
    }

    //    قدرمطلق
    string larger = removeLeadingZeros(thisIsGreater ? str : other.str);
    string smaller = removeLeadingZeros(thisIsGreater ? other.str : str);

    int carry = 0;
    string resultStr = "";
    int largerSize = larger.size();
    int smallerSize = smaller.size();

    for (int i = 1; i <= largerSize; i++) {
        int digit1 = larger[largerSize - i] - '0';
        int digit2 = (i <= smallerSize) ? smaller[smallerSize - i] - '0' : 0;

        int sub = digit1 - digit2 - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        resultStr.insert(resultStr.begin(), sub + '0');
    }

    result.str = removeLeadingZeros(resultStr);
    result.size = result.str.size();
    result.sign = (thisIsGreater) ? sign : !sign;

    return result;
}

bigNumber bigNumber::multiply(bigNumber other) {
    int a = size;
    int b = other.size;

    bigNumber result;
    result.sign = (sign != other.sign); 
    result.size = a + b;
    result.str = string(a + b, '0');  

    for (int i = a - 1; i >= 0; --i) {
        for (int j = b - 1; j >= 0; --j) {
            int mul = (str[i] - '0') * (other.str[j] - '0');
            int sum = (mul + (result.str[i + j + 1] - '0'));
            result.str[i + j + 1] = (sum % 10) + '0';  
            result.str[i + j] += sum / 10;  //  به موقعیت قبلی
        }
    }
    result.str = removeLeadingZeros(result.str);
    result.size = result.str.size();
    return result;
}
/*
bigNumber bigNumber::divide(bigNumber divisor) {

    
    if (divisor.str == "0") {
        throw runtime_error("Division by zero is undefined");
        
        
    }else if (size > divisor.size) {
        thisIsGreater = true;
    } else if (size == divisor.size) {
        int strSize = str.size();
        for (int i = 0; i < strSize; ++i) {
            if (str[i] > divisor.str[i]) {
                thisIsGreater = true;
                break;
            } else if (str[i] < divisor.str[i]) {
                thisIsGreater = false;
                break;
            }
        }
    }

    bigNumber result;
    result.sign = (sign != divisor.sign);  // علامت نتیجه ضرب
    bigNumber dividend = *this;
    bigNumber quotient("0");
    bigNumber current("0");

    dividend.str = dividend.removeLeadingZeros(dividend.str);
    divisor.str = divisor.removeLeadingZeros(divisor.str);

    bool resultSign = (dividend.sign != divisor.sign);
    dividend.sign = divisor.sign = false;

    for (size_t i = 0; i < dividend.str.size(); i++) {
        current.str += dividend.str[i];
        current.str = current.removeLeadingZeros(current.str);

        int count = 0;
        while (current.size > divisor.size || 
               (current.size == divisor.size && current.str >= divisor.str)) {
            current = current.subtract(divisor);
            count++;
        }
        quotient.str += (count + '0');
    }

    quotient.str = quotient.removeLeadingZeros(quotient.str);

    if (quotient.str.empty()) {
        quotient.str = "0";
    }

    quotient.size = quotient.str.size();
    quotient.sign = resultSign;
    return quotient;
}

*/


bigNumber bigNumber::power(int exp) {
    bigNumber result ("1");
    bigNumber base =*this;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result.multiply(base);
        }
        base = base.multiply(base);
        exp /= 2;
    }
    return result;
}


    bigNumber bigNumber::factorial(int n) {
        bigNumber result("1");
        for (int i = 2; i <= n; i++) {
            bigNumber current(to_string(i));
            result = result.multiply(current);
        }

        return result;
    }


 bigNumber bigNumber::karatsuba(bigNumber other) {
    if (size == 1 || other.size == 1) {
        return multiply(other);
    }
    
     size_t maxLen = max(size, other.size);
    while (str.size() < maxLen) str = '0' + str;
    while (other.str.size() < maxLen) other.str = '0' + other.str;

    int n = maxLen / 2;

    bigNumber high1(str.substr(0, str.size() - n));
    bigNumber low1(str.substr(str.size() - n));
    bigNumber high2(other.str.substr(0, other.str.size() - n));
    bigNumber low2(other.str.substr(other.str.size() - n));

    bigNumber z0 = low1.karatsuba(low2);
    bigNumber z1 = (low1.add(high1)).karatsuba(low2.add(high2));
    bigNumber z2 = high1.karatsuba(high2); 

     z1 = z1.subtract(z0);
     z1 = z1.subtract(z2);

    
    z2.shiftLeft(2 * n);        // z2 * 10^(2n)
    z1.shiftLeft(n);        // middle * 10^n

    bigNumber result = (z2.add(z1)).add(z0);

    return result;
}


string bigNumber::removeLeadingZeros(const string& str) {
    size_t pos = str.find_first_not_of('0');
    if (pos == string::npos) {
        return "0";  
    }
    return str.substr(pos);
}





void bigNumber::print() {
    if(sign)
    cout<<'-';
    cout<<str;
}

int main() {
    int  s, h,n,p;

    string str1, str2;



    cout << "\nEnter first string: ";
    cin >> str1; 

    cout << "Enter second string: ";
    cin >> str2; 

    bigNumber num3(str1);
    bigNumber num4(str2);
    num3.shiftRight();

    cout << "\nFirst number after shifting right by 1: ";
    num3.print();

   
    num4.shiftLeft();
    cout << "\nSecond number after shifting left by 1: ";
    num4.print();

    cout << "\nEnter number of positions to shift right: ";
    cin >> s;
    num3.shiftRight(s);
    cout << "First number after shifting right by " << s << ": ";
    num3.print();

    cout << "\nEnter number of positions to shift left: ";
    cin >> h;
    num4.shiftLeft(h);
    cout << "Second number after shifting left by " << h << ": ";
    num4.print();
    
    cout<<"\nA+B = ";
    bigNumber s_add = num3.add(num4);
    s_add.print(); 
    cout<<endl;

    cout<<"A-B = ";
    bigNumber s_subtract = num3.subtract(num4);
    s_subtract.print(); 
    cout<<endl;

    cout<<"A*B = ";
    cout<<"=";
    (num3.multiply(num4)).print();

    cout << "\nResult with karatsuba: ";
    bigNumber resultKar = num3.karatsuba(num4);
    resultKar.print();
    cout << endl;

    cout<<"A/B = ";
  // (num3.divide(num4)).print();
    cout<<"\nEnter a number between 0 and 100: ";
    cin>>n;
    bigNumber result = num3.factorial(n);
    result.print();

    cout<<"\nEnter the power: ";
    cin>>p;
    cout<<"The second number to the power ";
    num4.power(p).print();
    return 0;


}
