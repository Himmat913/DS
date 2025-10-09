#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter length of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter element to search: ";
    cin>>k;

    int low = 0, high = n-1, pos = -1;
    while (low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] == k) {
            pos = mid;
            break;
        }
        else if (arr[mid] < k)
            low = mid+1;
        else
            high = mid-1;
    }

    if (pos != -1)
        cout<<"Element found at index: "<<pos<<endl;
    else
        cout<<"Element not found"<<endl;

    return 0;
}
