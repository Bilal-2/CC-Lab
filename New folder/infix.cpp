#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

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

int infix(string expression)
{
    stack<char> operators;
    stack<double> values;
    vector<string> tokens;

    string numBuffer;
    for (char c : expression) {
        if (isspace(c))
            continue;

        if (isdigit(c) || c == '.') {
            numBuffer += c;
        }
        else {
            if (!numBuffer.empty()) {
                tokens.push_back(numBuffer);
                numBuffer.clear();
            }
            tokens.push_back(string(1, c));
        }
    }
    if (!numBuffer.empty()) {
        tokens.push_back(numBuffer);
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

string infixToPrefix(const string& infix) {
    stack<char> operators;
    stack<string> values;

    string prefixExpression = "";
    string numBuffer = "";

    for (int i = infix.size() - 1; i >= 0; i--) {
        char c = infix[i];

        if (isdigit(c) || c == '.') {
            numBuffer = c + numBuffer;
        }
        else {
            if (!numBuffer.empty()) {
                values.push(numBuffer);
                numBuffer.clear();
            }

            if (c == ')') {
                operators.push(c);
            }
            else if (c == '(') {
                while (!operators.empty() && operators.top() != ')') {
                    string op(1, operators.top());
                    operators.pop();
                    string a = values.top();
                    values.pop();
                    string b = values.top();
                    values.pop();
                    values.push(op + a + b);
                }
                operators.pop();  // Pop the closing parenthesis
            }
            else {
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    string op(1, operators.top());
                    operators.pop();
                    string a = values.top();
                    values.pop();
                    string b = values.top();
                    values.pop();
                    values.push(op + a + b);
                }
                operators.push(c);
            }
        }
    }

    if (!numBuffer.empty()) {
        values.push(numBuffer);
    }

    while (!operators.empty()) {
        string op(1, operators.top());
        operators.pop();
        string a = values.top();
        values.pop();
        string b = values.top();
        values.pop();
        values.push(op + a + b);
    }

    prefixExpression = values.top();
    return prefixExpression;
}

double evaluatePrefix(string prefixExp) {
    stack<double> operandStack;
    int size = prefixExp.size() - 1;

    for (int i = size; i >= 0; i--) {
        if (isdigit(prefixExp[i])) {
            operandStack.push(prefixExp[i] - '0');
            cout << "Token: " << prefixExp[i] << endl;
        }
        else if (prefixExp[i] == ' ' || prefixExp[i] == '\t') {
            // Skip whitespace characters
            continue;
        }
        else {
            double o1 = operandStack.top();
            operandStack.pop();
            double o2 = operandStack.top();
            operandStack.pop();
            cout << "Token: " << prefixExp[i] << endl;
            cout << "Applied operator: " << prefixExp[i] << endl;
            cout << "Left: " << o2 << " Right: " << o1 << " Result: ";
            if (prefixExp[i] == '+') {
                operandStack.push(o1 + o2);
                cout << o1 + o2 << endl;
            }
            else if (prefixExp[i] == '-') {
                operandStack.push(o1 - o2);
                cout << o1 - o2 << endl;
            }
            else if (prefixExp[i] == '*') {
                operandStack.push(o1 * o2);
                cout << o1 * o2 << endl;
            }
            else if (prefixExp[i] == '/') {
                operandStack.push(o1 / o2);
                cout << o1 / o2 << endl;
            }
            else {
                cout << "Invalid Expression" << endl;
                return -1;
            }
        }
    }
    return operandStack.top();
}

int evaluatePostfix(string exp) {
    stack<int> st;
    int result = 0;
    for (int i = 0; i < exp.size(); ++i) {
        if (isdigit(exp[i])) {
            int num = exp[i] - '0';
            st.push(num);
            cout << "Token: " << num << endl;
        }
        else if (exp[i] != ' ') {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            cout << "Token: " << exp[i] << endl;
            cout << "Applied operator: " << exp[i] << endl;
            cout << "Left: " << val2 << " Right: " << val1 << " Result: ";
            switch (exp[i]) {
            case '+':
                result = val2 + val1;
                break;
            case '-':
                result = val2 - val1;
                break;
            case '*':
                result = val2 * val1;
                break;
            case '/':
                result = val2 / val1;
                break;
            }
            st.push(result);
            cout << result << endl;
        }
    }
    return st.top();
}

void main() {

    //string expression;
    //cout << "Enter a mathematical expression: ";
    //getline(cin, expression);
   // cout << endl;

    // Evaluate Infix
    // infix(expression);

    // Evaluate Prefix
    string prefixExp = "-*+123+45";
    cout << "Prefix Expression: " << prefixExp << endl;
    double result = evaluatePrefix(prefixExp);
    cout << "Result: " << result << endl;

    // Evaluate Postfix
    // string exp = "2 3 1 * + 9 -";
    // cout << "Postfix expression: " << exp << endl;
    // int result = evaluatePostfix(exp);
    // cout << "Result: " << result << endl;

    // Convert Infix to Prefix
    // string prefixExpression = infixToPrefix(expression);
    // cout << "Prefix Expression: " << prefixExpression << endl;


    //evaluatePrefixExpression(prefixExpression);
}
