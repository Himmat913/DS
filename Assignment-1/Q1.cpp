#include <iostream>
using namespace std;

int arr[100];
int n = 0;

void create() {
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0 || n > 100) {
        cout << "Invalid size.\n";
        n = 0;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}

void display() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    if (n >= 100) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }
    int pos, value;
    cout << "Enter position to insert (1 to " << n + 1 << "): ";
    cin >> pos;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position.\n";
        return;
    }
    cout << "Enter the value to insert: ";
    cin >> value;
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
    cout << "Element inserted.\n";
}

void deletion() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    int pos;
    cout << "Enter the position to delete (1 to " << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted from position " << pos << ".\n";


}

void linearSearch() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int value;
    bool found = false;
    cout << "Enter the element to be searched: ";
    cin >> value;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cout << "Element found at position: " << i + 1 << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Element not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: create(); 
			break;
            case 2: display(); 
			break;
            case 3: insert(); 
			break;
            case 4: deletion(); 
			break;
            case 5: linearSearch(); 
			break;
            case 6: cout << "Exited.\n"; 
			break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}
