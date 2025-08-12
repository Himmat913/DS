#include <iostream>
using namespace std;

int main() {
	int a[3][3] = {{1,2,8},{3,4,0},{5,6,2}};
	int rowSum = 0;
	int colSum = 0;
	
	for(int i=0; i<3; i++) {
		rowSum=0;
		for(int j=0; j<3; j++) {
			rowSum += a[i][j];
		}
		cout<<"Sum of row "<<i+1<<" elements:"<<rowSum<<endl;
	}
	
	for(int i=0; i<3; i++) {
		colSum=0;
		for(int j=0; j<3; j++) {
			colSum += a[j][i];
		}
		cout<<"Sum of col "<<i+1<<" elements:"<<colSum<<endl;
	}
	
	
	return 0;
}