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
        if(head == nullptr) {
            head = temp;
        } else {
            Node* ptr = head;
            while(ptr->next != nullptr) ptr = ptr->next;
            ptr->next = temp;
        }
    }

    int countOccurrences(int key) {
        Node* ptr = head;
        int cnt = 0;
        while(ptr != nullptr) {
            if(ptr->data == key) cnt++;
            ptr = ptr->next;
        }
        return cnt;
    }

    void deleteAll(int key) {
        while(head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        Node* ptr = head;
        while(ptr != nullptr && ptr->next != nullptr) {
            if(ptr->next->data == key) {
                Node* temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            } else {
                ptr = ptr->next;
            }
        }
    }

    void display() {
        Node* ptr = head;
        if(ptr == nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        while(ptr != nullptr) {
            cout<<ptr->data;
            if(ptr->next != nullptr) cout<<"->";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);

    int key;
    cout<<"Enter key to count and delete: ";
    cin>>key;

    int count = list.countOccurrences(key);
    cout<<"Count: "<<count<<endl;

    list.deleteAll(key);
    cout<<"Updated Linked List: ";
    list.display();

    return 0;
}
