#include <iostream>
using namespace std;

int main() {
    int n=8;
    int arr[n]={1,2,6,4,9,0,5,3};
    int count=0;

    for(int i=0; i<n; i++) {
         for(int j=i+1; j<n; j++) {
            if(arr[i]>arr[j]) {
                count++;
            }
         }
    }

    cout<<"The number of inversions in the given array are : "<<count<<endl;
}