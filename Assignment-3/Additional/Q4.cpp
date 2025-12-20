#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    int temp[100000], ans[100000];
    for (int i = 0; i < n; i++) cin >> temp[i];

    stack<int> st;  

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && temp[st.top()] <= temp[i])
            st.pop();

        if (st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top() - i;

        st.push(i);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
