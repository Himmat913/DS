#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if(tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    int size() {
        if(tail == nullptr) return 0;
        int count = 0;
        Node* temp = tail->next;
        do {
            count++;
            temp = temp->next;
        } while(temp != tail->next);
        return count;
    }

    void display() {
        if(tail == nullptr) {
            cout<<"List is empty.\n";
            return;
        }
        Node* temp = tail->next;
        cout<<"Circular Linked List: ";
        do {
            cout<<temp->data<<" ";
            temp = temp->next;
        } while(temp != tail->next);
        cout<<endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val;

    while(true) {
        cout<<"\n CIRCULAR LINKED LIST MENU \n";
        cout<<"1. Insert\n";
        cout<<"2. Display Size\n";
        cout<<"3. Display List\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter value: ";
                cin>>val;
                cll.insert(val);
                break;

            case 2:
                cout<<"Size: "<<cll.size()<<endl;
                break;

            case 3:
                cll.display();
                break;

            case 4:
                return 0;

            default:
                cout<<"Invalid choice.\n";
        }
    }
}
