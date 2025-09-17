#include <iostream>
#include <stack>
using namespace std;

string reverseStr(string str) {
    stack<char> st;
    int i;
    for(i=0; i<str.length(); i++) {
        st.push(str[i]);
    }

    string rev="";
    while(!st.empty()) {
        rev = rev + st.top();
        st.pop();
    }
    return rev;
}

int main() {
    string str = "DataStructure";
    cout << "Original: " << str << endl;
    string ans = reverseStr(str);
    cout << "Reversed: " << ans << endl;
    return 0;
}
