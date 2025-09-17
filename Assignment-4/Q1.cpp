#include <iostream>
using namespace std;

const int n = 5;
int queue[n];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if(rear == n-1) {
        cout<<"Queue is full"<<endl;
    } else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = val;
        cout<<val<<" enqueued"<<endl;
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        cout<<"Queue is empty"<<endl;
    } else {
        cout<<queue[front]<<" dequeued"<<endl;
        front++;
    }
}

void isEmpty() {
    if(front == -1 || front > rear) cout<<"Queue is empty"<<endl;
    else cout<<"Queue is not empty"<<endl;
}

void isFull() {
    if(rear == n-1) cout<<"Queue is full"<<endl;
    else cout<<"Queue is not full"<<endl;
}

void peek() {
    if(front == -1 || front > rear) cout<<"Queue is empty"<<endl;
    else cout<<"Front element: "<<queue[front]<<endl;
}

void display() {
    if(front == -1 || front > rear) {
        cout<<"Queue is empty"<<endl;
    } else {
        cout<<"Queue elements: ";
        for(int i = front; i <= rear; i++) {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int choice, val;
    do {
        cout<<"\n1.Enqueue\n2.Dequeue\n3.Is empty\n4.Is full\n5.Peek\n6.Display\n7.Exit\n";
        cin>>choice;
        switch(choice) {
            case 1: 
                cout<<"Enter value to enqueue: "; cin>>val;
                enqueue(val);
                break;
            case 2: dequeue(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: peek(); break;
            case 6: display(); break;
            case 7: cout<<"Exited program"; break;
            default: cout<<"Invalid choice"; break;
        }
    } while(choice != 7);
    return 0;
}
