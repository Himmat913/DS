#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> s;
    int i;

    for(i=0; i<postfix.length(); i++) {
        char ch = postfix[i];

        if(ch>='0' && ch<='9') {
            s.push(ch-'0');
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch(ch) {
                case '+': s.push(val1+val2); 
                          break;
                case '-': s.push(val1-val2);
                          break;
                case '*': s.push(val1*val2);
                          break;
                case '/': s.push(val1/val2); 
                          break;
            }
        }
    }

    return s.top();
}

int main() {
    string postfix;
    cout<<"Enter the postfix expression: ";
    cin>>postfix;

    int result = evaluatePostfix(postfix);
    cout<<"Result: "<<result<<endl;

    return 0;
}
