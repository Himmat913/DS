#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int val) {
    int sz = q.size();
    q.push(val);
    for(int i=0; i<sz; i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop() {
    if(q.empty()) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<q.front()<<" popped"<<endl;
    q.pop();
}

void peek() {
    if(q.empty()) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Top element: "<<q.front()<<endl;
}

bool isEmpty() {
    return q.empty();
}

int main() {
    push(10);
    push(20);
    push(30);
    peek();
    pop();
    peek();
    pop();
    pop();
    if(isEmpty()) cout<<"Stack is empty"<<endl;
    return 0;
}
