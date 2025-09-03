#include <iostream>
using namespace std;

int main() {
    int n = 8;
    int arr[n] = {2,2,3,6,8,0,0,-1};
    int count = 0;

    for(int i=0; i<n; i++) {
        bool isDistinct = true;
        for(int j=0; j<i;j++) {
            if(arr[i]==arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if(isDistinct) {
            count++;
        }
    }

    cout<<"Number of distinct elements in the given array is : "<<count<<endl;
    
    return 0;
}