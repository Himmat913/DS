#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n*(n+1)/2];
    cout<<"Enter lower triangular elements:";
    for(int i=0;i<n*(n+1)/2;i++)
    cin>>arr[i];

    cout<<"Matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(i>=j)
            cout<<arr[i*(i+1)/2+j]<<" ";
            else 
            cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
