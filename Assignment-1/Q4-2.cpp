#include <iostream>
using namespace std;

int main() {
	int a[3][2] = {{1,2},{3,4},{5,6}};
	int b[2][2] = {{7,0},{3,1}};
	int c[3][2]={0};
	for(int i=0; i<3; i++) {
		for(int j=0; j<2; j++) {
			for(int k=0; k<2; k++)
			c[i][j]+=a[i][k]*b[k][j];
		}
	}
	
	for(int i=0; i<3; i++) {
		for(int j=0; j<2; j++) {
			cout<<c[i][j]<<" ";
		}
		cout<<endl; 
	}
	
	return 0;
}