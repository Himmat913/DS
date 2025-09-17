#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if(op=='+' || op=='-') 
    return 1;
    if(op=='*' || op=='/') 
    return 2;
    return 0;
}

string postfix(string infix) {
    stack<char> s;
    string postfix = "";
    int i;

    for(i=0; i<infix.length(); i++) {
        char ch = infix[i];

        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')) {
            postfix = postfix + ch;
        }

        else if(ch=='(') {
            s.push(ch);
        }

        else if(ch==')') {
            while(!s.empty() && s.top()!='(') {
                postfix = postfix + s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        }
   
        else {
            while(!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix = postfix + s.top();
                s.pop();
            }
            s.push(ch);
        }
    }


    while(!s.empty()) {
        postfix = postfix + s.top();
        s.pop();
    }

    return postfix;
}


int main() {
    string expr;
    cout<<"Enter the infix expression: ";
    cin>>expr;
    
    cout<<"The postfix expression is: "<<postfix(expr)<<endl;

    return 0;
}
