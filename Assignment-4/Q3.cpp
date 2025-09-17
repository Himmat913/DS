#include <iostream>
using namespace std;

const int n = 100;
int queue[n];

int main() {
    int size, i;
    cout<<"Enter number of elements in the queue: ";
    cin>>size;
    cout<<"Enter the elements: ";
    for(i=0; i<size; i++) {
        cin>>queue[i];
    }

    int mid = size/2;
    int result[n];
    int index = 0;
    for(i=0; i<mid; i++) {
        result[index++] = queue[i];
        result[index++] = queue[i + mid];
    }

    if(size%2 != 0) {
        result[index++] = queue[size-1];
    }

    cout<<"Interleaved queue: ";
    for(i=0; i<size; i++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}
