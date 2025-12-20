#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    private :
    stack<int> st;
    int minEle;

    public : 
        SpecialStack() {
            minEle = -1;
        }

        void push(int x) {
            if(st.empty()) {
                st.push(x);
                minEle = x;
            } else if(x < minEle) {
                st.push(2*x-minEle);
                minEle = x;
            } else {
                st.push(x);
            }
        }

        void pop() {
            if(st.empty()) {
                cout << "Stack is empty." << endl;
                return;
            }
            int t = st.top();
            st.pop();
            if(t < minEle) {
                minEle = 2*minEle - t;
            }
        }

        int peek() {
            if(st.empty()) {
                cout << "Stack is empty." << endl;
                return;
            }
            int t = st.top();
            return (minEle > t) ? minEle : t;
        }

        int getMin() {
            if(st.empty()) {
                return -1;
            }
            return minEle;
        }
    
};

int main() {
    SpecialStack st;
    
    st.push(2);
    st.push(3);
    cout << st.peek() << " ";
    st.pop();
    cout << st.getMin() << " ";
    st.push(1);
    cout << st.getMin() << " ";

    return 0;
}