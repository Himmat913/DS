#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        if(head == nullptr) {
            cout<<"List is empty.\n";
            return;
        }
        Node* temp = head;
        cout<<"Doubly Linked List: ";
        while(temp != nullptr) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val;

    while(true) {
        cout<<"\n DOUBLY LINKED LIST MENU \n";
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
                dll.insert(val);
                break;

            case 2:
                cout<<"Size: "<<dll.size()<<endl;
                break;

            case 3:
                dll.display();
                break;

            case 4:
                return 0;

            default:
                cout<<"Invalid choice.\n";
        }
    }
}
