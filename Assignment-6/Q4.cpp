#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
    char data;
    Node* prev;
    Node* next;
    Node(char c) {
        data = c;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insert(char c) {
        Node* n = new Node(c);
        if(head == nullptr) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    bool isPalindrome() {
        if(head == nullptr) return true; 
        Node* l = head;
        Node* r = tail;
        while(l != r && l->prev != r) { 
            if(l->data != r->data) 
            return false;
            l = l->next;
            r = r->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);

    for(size_t i=0;i<s.length();++i) {
        dll.insert(s[i]);
    }

    if(dll.isPalindrome()) 
    cout<<"Palindrome.\n";
    else 
    cout<<"Not palindrome.\n";

    return 0;
}
