#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isMatching(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}
bool isBalanced(const string& expression)
{
    stack<char> brackets;
    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (brackets.empty())
                return false;
            if (!isMatching(brackets.top(), ch))
                return false;
            brackets.pop();
        }
    }
    return brackets.empty();
}
int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    if (isBalanced(expression))
        cout << "Brackets are balanced." << endl;
    else
        cout << "Brackets are not balanced." << endl;
    return 0;
}
