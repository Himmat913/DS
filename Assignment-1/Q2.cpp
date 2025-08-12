#include <iostream>
using namespace std;

int main() {
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cout<<"Element:"<<i+1<<" ";
		cin>>arr[i];
	}
	
	int pos;
	
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n;) {
			if(arr[i]==arr[j]) {
				pos=j;
				for(int k=pos; k<n; k++) {
					arr[k]=arr[k+1];
				}
				n--;
			}else {
				j++;
			}
			
		}
	}
	
	cout<<"Array elements are:";
    for(int i=0;i<n; i++) {
		cout<<arr[i]<<" ";
	}
	
}