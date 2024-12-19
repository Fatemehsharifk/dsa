#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <SFML/Graphics.hpp>
using namespace std;

int precedence(char op)
{   if (op == '+' || op == '-')return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^')return 3;
    return 0;}

bool isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; }


string infixToPostfix(string infix)
{   string postfix;
    stack<char> stack;
    for (int i = 0; i < infix.size(); ++i){
        char c = infix[i];
        if (isspace(c))continue;
        if (isdigit(c) || isalpha(c) || c == '~'){
            if (c == '~'){
                postfix += c;
                i++;
            }

            while (i < infix.size() && (isdigit(infix[i]) || isalpha(infix[i])))
            {postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;
        }
        else if (c == '('){
            stack.push(c);
        }
        else if (c == ')'){
            while (!stack.empty() && stack.top() != '(')
            {   postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            if (!stack.empty())
                stack.pop();
        }else if (isOperator(c)){
            while (!stack.empty() && precedence(stack.top()) >= precedence(c))
            {   postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty()){
        postfix += stack.top();
        postfix += ' ';
        stack.pop();
    }
    return postfix;
}


string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {   if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    string prefix;
    stack<char> operators;
    for (int i = 0; i < infix.size(); ++i){
        char c = infix[i];
        if (isspace(c))continue;
        if (isdigit(c) || c == '~'){
            while (i < infix.size() && (isdigit(infix[i]) || infix[i] == '~')){
                prefix += infix[i];
                i++;
            }
            prefix += ' ';
            i--;
        }
        else if (c == '('){
            operators.push(c);
        }
        else if (c == ')'){
            while (!operators.empty() && operators.top() != '('){
                prefix += operators.top();
                prefix += ' ';
                operators.pop();
            }
            operators.pop();
        }
        else if (isOperator(c)){
            while (!operators.empty() && precedence(operators.top()) > precedence(c)){
                prefix += operators.top();
                prefix += ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()){
        prefix += operators.top();
        prefix += ' ';
        operators.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}


int calculations(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}


float calculations(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}


int postfixAnswer(string postfix){
    stack<int> stack;
    for (int i = 0; i < postfix.size(); ++i){
        if (isspace(postfix[i]))continue;
        if (isdigit(postfix[i]) || postfix[i] == '~'){
            string num;
            if (postfix[i] == '~'){
                num += '-';
                i++;
            }
            while (i < postfix.size() && isdigit(postfix[i])){
                num += postfix[i];
                i++;
            }
            stack.push(stoi(num));
        }
        else if (isOperator(postfix[i])){
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result = calculations(a, b, postfix[i]);
            stack.push(result);
        }
    }
    return stack.top();
}

float postfixAnswerVar(string postfix ,float x) {
    float num ;
    stack<float> stack;
    for (int i = 0; i < postfix.size(); ++i) {
        if (isspace(postfix[i])) continue;
        if ( postfix[i] == '~' || isalpha(postfix[i]) || isdigit(postfix[i])) {
            if(isdigit(postfix[i]) || postfix[i] == '~'){
                string numberStr;
                while (i< postfix.size() && (isdigit(postfix[i]) || postfix[i] == '.' || postfix[i] == '~')) {
                    if (postfix[i] == '~') {
                        numberStr += '-';
                        i++;
                    } else {
                        numberStr += postfix[i];
                        i++;
                    }
                }
                num = stof(numberStr);
                stack.push(num);
                i--;
            }else if((isalpha(postfix[i]))) {
                num = x;
                stack.push(num);
            }
        }else if(isOperator(postfix[i])) {
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            float result = calculations(a, b, postfix[i]);
            stack.push(result);
        }
    }
    return stack.top();
}



int prefixAnswer(string prefix)
{
    stack<int> stack;
    reverse(prefix.begin(), prefix.end());

    for (int i = 0; i < prefix.size(); ++i){
        string num;
        if (isspace(prefix[i]))
            continue;

        if (!isOperator(prefix[i])){

            while (i < prefix.size() && !isspace(prefix[i])){
                while (i < prefix.size() && (isdigit(prefix[i]) || prefix[i] == '~')){
                    if(isdigit(prefix[i]))
                    {num += prefix[i];
                        i++;
                    }if (prefix[i] == '~'){
                        num += '-';
                        i++;
                    }
                }
                reverse(num.begin(), num.end());
            }

            stack.push(stoi(num));
            i--;
        }else if (isOperator(prefix[i])){
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            int result = calculations(a, b, prefix[i]);
            stack.push(result);
        }
    }

    return stack.top();
}

string VarToNum(string str, int value) {
    string result;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'x') {
            result += to_string(value);
        } else {
            result += str[i];
        }
    }
    return result;
}

int main()
{    string infix;
    int input;

    cout << "Select your input type.\n1.Number\n2.Variable\n3.Exit\n";
    cin >> input;

    if (input == 1) {
        cout << "Enter the equation: ";
        cin >> infix;
        cout << "\nInfix: " << infix << endl;
        string postfix = infixToPostfix(infix);
        cout << "Postfix: " << postfix << endl;
        cout << "Postfix Answer: " << postfixAnswer(postfix) << endl;
        string prefix = infixToPrefix(infix);
        cout << "Prefix: " << prefix << endl;
        cout << "Prefix Answer: " << prefixAnswer(prefix) << endl;
    } else if(input == 2){
        int option;
        cout << "\nDo you want to give a number or see the plot?\n1.Number\n2.Plot\n" << endl;
        cin >> option;
        string infix;
        cout << "Enter the equation: ";
        cin >> infix;
        int x;
        if (option == 1) {
            cout << "\nEnter value: ";
            cin >> x;
            string replacedInfix = VarToNum(infix, x);
            string postfix = infixToPostfix(replacedInfix);
            cout<< postfixAnswer(postfix);
        }else{
        sf::RenderWindow window(sf::VideoMode(800, 600), "Plot");
        window.setFramerateLimit(60);

        sf::VertexArray axes(sf::Lines, 4);
        axes[0].position = sf::Vector2f(400, 0); // y
        axes[1].position = sf::Vector2f(400, 600);
        axes[2].position = sf::Vector2f(0, 300); // x
        axes[3].position = sf::Vector2f(800, 300);
        for (int i = 0; i < 4; i++) axes[i].color = sf::Color::Black;


        sf::VertexArray points(sf::Points);

        float scale = 50.0f; // مقیاس
        for (float x = -10.0f; x <= 10.0f; x += 0.0001f) {
            float y = postfixAnswerVar(infixToPostfix(infix), x);
            float screenX = 400 + x * scale;
            float screenY = 300 - y * scale;

            if (screenY >= 0 && screenY <= 600) {
                points.append(sf::Vertex(sf::Vector2f(screenX, screenY), sf::Color::Red));
            }
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::White);
            window.draw(axes);
            window.draw(points);
            window.display();
        }}

    }if(input == 3){
        return 0;
    }


}


