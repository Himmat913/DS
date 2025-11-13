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

    void insert_beg(int val) {
        Node* newNode = new Node(val);
        if(tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void insert_end(int val) {
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

    void insert_after(int key, int val) {
        Node* temp = tail->next;
        do {
            if(temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                if(temp == tail) {
                    tail = newNode;
                }
                cout<<"Value "<<val<<" inserted after "<<key<<endl;
            }

            temp = temp->next;
        }while(temp != tail->next);
    }

    void insert_before(int key, int val) {
        Node* temp = tail->next;
        Node* prev = tail;
        do {
            if(temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp;
                prev->next = newNode;
                if(temp == tail->next) {
                    tail->next = newNode;
                }
            }
        }while(temp != tail->next);
    }

    void display() {
    if (tail == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* head = tail->next;
    Node* temp = head;

    cout<<"Circular List: ";
    do {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);

    cout<<head->data<<endl;
}

};

int main() {
    CircularLinkedList cll;
    int choice, data, key;

    while (true) {
        cout << "\n CIRCULAR LINKED LIST MENU \n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Node\n";
        cout << "4. Insert Before Node\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cll.insert_beg(data);
                break;

            case 2:
                cout << "Enter data: ";
                cin >> data;
                cll.insert_end(data);
                break;

            case 3:
                cout << "Enter key (existing node): ";
                cin >> key;
                cout << "Enter new data: ";
                cin >> data;
                cll.insert_after(key, data);
                break;
            
            case 4:
                cout << "Enter key (existing node): ";
                cin >> key;
                cout << "Enter new data: ";
                cin >> data;
                cll.insert_before(key, data);
                break;
                
            case 5:
                cll.display();
                break;

            case 6:
                cout << "Exited.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
