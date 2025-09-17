#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertBeg(int num) {
        Node* temp = new Node(num);
        temp->next = head;
        head = temp;
    }

    void insertEnd(int num) {
        Node* temp1 = new Node(num);
        if(head == nullptr) {
            head = temp1;
            return;
        }
        Node* temp2 = head;
        while(temp2->next != nullptr) temp2 = temp2->next;
        temp2->next = temp1;
    }

    void insertBetween(int val1, int val2, int num) {
        if(head == nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp1 = head;
        while(temp1 != nullptr && temp1->next != nullptr) {
            if(temp1->data == val1 && temp1->next->data == val2) {
                Node* temp2 = new Node(num);
                temp2->next = temp1->next;
                temp1->next = temp2;
                return;
            }
            temp1 = temp1->next;
        }
        cout<<"No such adjacent nodes found"<<endl;
    }

    void deleteBeg() {
        if(head == nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if(head == nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpec(int num) {
        if(head == nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->data == num) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != num) temp = temp->next;
        if(temp->next == nullptr) {
            cout<<"Element not found"<<endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    int search(int num) {
        Node* temp = head;
        int pos = 1;
        while(temp != nullptr) {
            if(temp->data == num) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if(head == nullptr) {
            cout<<"Empty list"<<endl;
            return;
        }
        Node* temp = head;
        while(temp != nullptr) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    LinkedList list;
    int choice, num, val1, val2;
    while(true) {
        cout<<"\n(1) Insertion at the beginning.\n(2) Insertion at the end.\n(3) Insertion in between\n(4) Deletion from the beginning.\n(5) Deletion from the end.\n(6) Deletion of a specific node.\n(7) Search for a node.\n(8) Display all nodes\nEnter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"Enter the number: "; cin>>num;
                list.insertBeg(num);
                break;
            case 2:
                cout<<"Enter the number: "; cin>>num;
                list.insertEnd(num);
                break;
            case 3:
                cout<<"Enter the number to insert: "; cin>>num;
                cout<<"Enter the two adjacent node values: "; cin>>val1>>val2;
                list.insertBetween(val1, val2, num);
                break;
            case 4:
                list.deleteBeg();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout<<"Enter the number to delete: "; cin>>num;
                list.deleteSpec(num);
                break;
            case 7:
                cout<<"Enter the number to search: "; cin>>num;
                if(list.search(num) == -1) cout<<"Element not found"<<endl;
                else cout<<"Found at position "<<list.search(num)<<endl;
                break;
            case 8:
                list.display();
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
