#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7}; 
    int n = 7;
    int low = 0, high = n-2; 
    int missing = n;       

    while (low <= high) {
        int mid = low + (high-low)/2;
        if (arr[mid] != mid+1) {
            missing = mid+1;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    cout<<"Missing number: "<<missing<<endl;
    return 0;
}
