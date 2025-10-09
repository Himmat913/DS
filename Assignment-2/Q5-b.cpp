#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[3*n-2];
    cout<<"Enter elements in order ("<<n-1<<" lower diagonal elements, "<<n<<" main diagonal elements, "<<n-1<<" upper diagonal elements):";
    for(int i=0;i<3*n-2;i++) {
    cin>>arr[i];
    }

    cout<<"Matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-j==1)
            cout<<arr[i-1]<<" ";
            else if(i==j)
            cout<<arr[n+i-1]<<" ";
            else if(j-i==1)
            cout<<arr[2*n+i-1]<<" ";
            else 
            cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
