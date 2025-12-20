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
        if (tail == NULL) return;

        Node* temp = tail->next;
        Node* prev = tail;

        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp;
                prev->next = newNode;

                if (temp == tail->next) {
                    tail->next = newNode; 
                }
                return; 
            }

            prev = temp;
            temp = temp->next;

        } while (temp != tail->next);
}


    void deleteNode(int key) {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = tail->next;
        Node* prev = tail;

        if (temp == tail && temp->data == key) {
            delete temp;
            tail = nullptr;
            cout << "Node " << key << " deleted.\n";
            return;
        }

        do {
            if (temp->data == key) {
                prev->next = temp->next;
                if (temp == tail)
                    tail = prev;
                delete temp;
                cout<<"Node "<<key<<" deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != tail->next);

        cout<<"Node "<<key<<" not found.\n";

    }

    void search(int key) {
        if (tail == nullptr) {
            cout<<"List is empty.\n";
            return;
        }
        Node* temp = tail->next;
        int pos = 1;
        do {
            if(temp->data == key) {
                cout<<"Node "<<key<<" found at position "<<pos<<endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != tail->next);
        cout<<"Node "<<key<<" not found.\n";
    }

    void display() {
        if (tail == nullptr) {
            cout<<"List is empty.\n";
            return;
        }
        Node* temp = tail->next;
        cout<<"Circular List: ";
        do {
            cout<<temp->data<<" ";
            temp = temp->next;
        } while (temp != tail->next);
        cout<<endl;
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
        cout << "5. Delete Node\n";
        cout << "6. Search Node\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
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
                cout << "Enter node to delete: ";
                cin >> key;
                cll.deleteNode(key);
                break;

            case 6:
                cout << "Enter node to search: ";
                cin >> key;
                cll.search(key);
                break;

            case 7:
                cll.display();
                break;

            case 8:
                cout << "Exited.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
