#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;
    int i;
    for(i=0; i<expr.length(); i++) {
        char ch = expr[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(s.empty()) {
                return false;
            }
            char topChar = s.top();
            s.pop();
            if((ch == ')' && topChar != '(') ||
               (ch == '}' && topChar != '{') ||
               (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if(isBalanced(expr)) {
        cout << "Balanced Parentheses" << endl;
    } else {
        cout << "Not Balanced Parentheses" << endl;
    }

    return 0;
}
