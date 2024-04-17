#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the given character is an operand
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to convert prefix expression to postfix expression
string prefixToPostfix(string prefix) {
    stack<string> s;

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            // Push operands to the stack
            s.push(string(1, prefix[i]));
        }
        else {
            // Pop two operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // Concatenate operands and the operator
            string temp = op1 + op2 + prefix[i];

            // Push the result back to the stack
            s.push(temp);
        }
    }

    return s.top();
}

int main() {
    string prefix;

    cout << "Enter prefix expression: ";
    getline(cin, prefix);

    string postfix = prefixToPostfix(prefix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
