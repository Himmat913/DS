#include <iostream>
#include <stack>
using namespace std;

bool checkSortable(int A[], int n) {
    stack<int> st;
    int expected = 1;

    for (int i = 0; i < n; i++) {
        int x = A[i];

        if (x == expected) {
            expected++;
        } else {
            if (!st.empty() && st.top() < x)
                return false;
            st.push(x);
        }

        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }

    return expected == n + 1;
}

int main() {
    int n;
    cin >> n;
    int A[1000];
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << (checkSortable(A, n) ? "Yes" : "No");
}
