#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter diagonal elements:";
    for(int i=0;i<n;i++) {
    cin>>arr[i];
    }
     
    cout<<"Matrix:"<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j)
            cout<<arr[i]<<" ";
            else 
            cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
