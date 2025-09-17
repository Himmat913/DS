#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7}; 
    int n = 7;
    int missing = n;

    for (int i = 0; i < n-1; i++) {
        if (arr[i] != i+1) {
            missing = i+1;
            break;
        }
    }

    cout<<"Missing number: "<<missing<<endl;
    return 0;
}
