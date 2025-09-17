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

    int findMiddle() {
        if (head == nullptr) {
            cout<<"List is empty" << endl;
            return -1;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void display() {
        Node* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->data;
            if (ptr->next != nullptr) cout << "->";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout<<"Linked List: ";
    list.display();

    cout<<"Middle element: "<<list.findMiddle()<<endl;

    return 0;
}
