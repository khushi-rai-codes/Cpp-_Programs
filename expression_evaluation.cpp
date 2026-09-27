#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;
    }

    return 0;
}

int evaluateExpression(const string& expression) {
    stack<int> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            continue;
        }

        if (isdigit(expression[i])) {
            int number = 0;

            while (i < expression.length() &&
                   isdigit(expression[i])) {
                number = number * 10 + (expression[i] - '0');
                i++;
            }

            i--;
            values.push(number);
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operators.empty() &&
                   operators.top() != '(') {

                int b = values.top();
                values.pop();

                int a = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                values.push(applyOperation(a, b, op));
            }

            if (!operators.empty()) {
                operators.pop();
            }
        }
        else {
            while (!operators.empty() &&
                   operators.top() != '(' &&
                   precedence(operators.top()) >=
                   precedence(expression[i])) {

                int b = values.top();
                values.pop();

                int a = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                values.push(applyOperation(a, b, op));
            }

            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int b = values.top();
        values.pop();

        int a = values.top();
        values.pop();

        char op = operators.top();
        operators.pop();

        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

int main() {
    string expression;

    cout << "Enter arithmetic expression: ";
    getline(cin, expression);

    try {
        int result = evaluateExpression(expression);
        cout << "Result: " << result << endl;
    }
    catch (...) {
        cout << "Invalid expression." << endl;
    }

    return 0;
}
