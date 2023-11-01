#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

double applyOperator(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
    }
}

string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> operators;

    for (char c : infix) {
        if (isspace(c))
            continue;

        if (isdigit(c) || isalpha(c)) {
            postfix += c;
            postfix += ' ';
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop(); // Pop the '('
        }
        else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }

    return postfix;
}

int main() {
    string expression;
    cout << "Enter a mathematical expression in infix notation: ";
    getline(cin, expression);

    string postfix = infixToPostfix(expression);
    cout << "Postfix expression: " << postfix << endl;

    stack<double> values;
    vector<string> tokens;

    istringstream postfixStream(postfix);
    string token;

    while (postfixStream >> token) {
        cout << "Token: " << token << endl;

        if (isdigit(token[0])) {
            values.push(stod(token));
        }
        else if (isOperator(token[0])) {
            double b = values.top();
            values.pop();
            double a = values.top();
            values.pop();
            values.push(applyOperator(a, b, token[0]));
            cout << "Applied operator: " << token[0] << endl;
            cout << "Left: " << a << " Right: " << b << " Result: " << applyOperator(a, b, token[0]) << endl;
        }
    }

    cout << "Result: " << values.top() << endl;
    return 0;
}