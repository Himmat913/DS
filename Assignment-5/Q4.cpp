#include<iostream>
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

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int num) {
        Node* temp = new Node(num);
        if (head == nullptr) {
            head = temp;
        } else {
            Node* ptr = head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* ptr = head;
        while (ptr != nullptr) {
            cout<<" "<<ptr->data;
            if (ptr->next != nullptr) cout<<"->";
            ptr = ptr->next;
        }
        cout<<"->NULL"<<endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    cout<<"Original List: ";
    list.display();

    list.reverse();

    cout<<"Reversed List: ";
    list.display();

    return 0;
}
