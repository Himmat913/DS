#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int val) {
    q1.push(val);
}

void pop() {
    if(q1.empty()) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    while(q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }
    cout<<q1.front()<<" popped"<<endl;
    q1.pop();
    swap(q1, q2);
}

void peek() {
    if(q1.empty()) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    while(q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }
    cout<<"Top element: "<<q1.front()<<endl;
    q2.push(q1.front());
    q1.pop();
    swap(q1, q2);
}

bool isEmpty() {
    return q1.empty();
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
