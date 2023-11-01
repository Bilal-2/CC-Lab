#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
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

int main() {

    string expression;
    cout << "Enter you Infix Expression: ";
    getline(cin, expression);
    stack<char> operators;
    stack<double> values;
    vector<string> tokens;

    for (char c : expression) {
        if (isspace(c))
            continue;
        tokens.push_back(string(1, c));
    }

    for (const string& token : tokens) {
        cout << "Token: " << token << endl;

        if (token == "(" || token == "{" || token == "[") {
            operators.push(token[0]);
        }
        else if (token == ")" || token == "}" || token == "]") {
            while (!operators.empty() && operators.top() != '(' && operators.top() != '{' && operators.top() != '[') {
                char op = operators.top();
                operators.pop();
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                values.push(applyOperator(a, b, op));
                cout << "Applied operator: " << op << endl;
                cout << "Left: " << a << " Right: " << b << " Result: " << applyOperator(a, b, op) << endl;
            }
            operators.pop(); // Pop the opening bracket
        }
        else if (isOperator(token[0])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token[0])) {
                char op = operators.top();
                operators.pop();
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                values.push(applyOperator(a, b, op));
                cout << "Applied operator: " << op << endl;
                cout << "Left: " << a << " Right: " << b << " Result: " << applyOperator(a, b, op) << endl;
            }
            operators.push(token[0]);
        }
        else {
            values.push(stod(token));
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        values.push(applyOperator(a, b, op));
        cout << "Applied operator: " << op << endl;
        cout << "Left: " << a << " Right: " << b << " Result: " << applyOperator(a, b, op) << endl;
    }

    cout << "Result: " << values.top() << endl;
    return 0;
}