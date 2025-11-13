#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class List {
private:
    Node* head;

public:
    List() {
        head = NULL;
    }

    void insert(int x) {
        Node* n = new Node(x);

        if(head == NULL) {
            head = n;
            head->next = head;
            return;
        }

        Node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }

        temp->next = n;
        n->next = head;
    }

    bool isCircular() {
        if(head == NULL) return false;

        Node* t = head->next;

        while(t != NULL && t != head) {
            t = t->next;
        }

        if(t == head)
            return true;
        else
            return false;
    }
};

int main() {
    List l;

    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);

    if(l.isCircular())
        cout<<"The list is circular.";
    else
        cout<<"The list is not circular.";

    return 0;
}
