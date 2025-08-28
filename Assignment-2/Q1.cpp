#include <iostream> 
using namespace std;

#define n 5
int stackk[n];
int top = -1;

void push(int val) {
	
	if(top==n-1) {
		cout<<"Stack overflow! Cannot push";
	} else {
		stackk[++top] = val;
	}
	cout<<val<<" pushed into the stack.\n";
	
}

void pop() {
	if(top==-1) {
		cout<<"Stack underflow! Nothing to pop";
	} else {
		cout<<stackk[top]<<" popped from the stack.\n";
		top--;
	}
}

void isEmpty() {
	if(top==-1) {
	} else {
		cout<<"Stack is not empty.\n";
	}
}

void isFull() {
	if(top==n-1) {
		cout<<"Stack is full.\n";
	} else {
		cout<<"Stack is not full.\n";
	}
}

void display() {
	cout<<"Stack elements are:";
	for(int i=top; i>=0; i--) {
		cout<<stackk[i]<<endl;
	}
}

void peek() {
	cout<<"Element at the top of the stack is:"<<stackk[top]<<endl;
}

int main() {
    	
		int x;
    do {
    	cout<<"\nEnter the digit corresponding to the operation you want to perform: Push(1)\nPull(2)\nIs empty?(3)\nIs full?(4)\nDisplay(5)\nPeek(6)\nExit(7)\n";
    	cin>>x;
    	switch(x) {
    		case 1: int val;
					cout<<"Enter the value to push:"<<endl;
					cin>>val;
					push(val);
					break;
			case 2: pop();
					break;
			case 3: isEmpty();
					break;
			case 4: isFull();
					break;
			case 5: display();
					break;
			case 6: peek();
					break;
			case 7: cout<<"Exited program.";
					break;
			default: cout<<"Invalid input!";
					break;
		}
	}while(x!=7);
	
	return 0;
}
