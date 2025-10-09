#include <iostream>
using namespace std;

void transpose(int arr1[100][3],int arr3[100][3]) {
    int i,j,k=1;
    arr3[0][0]=arr1[0][1];
    arr3[0][1]=arr1[0][0];
    arr3[0][2]=arr1[0][2];
    for(i=0;i<arr1[0][1];i++) {
        for(j=1;j<=arr1[0][2];j++) {
            if(arr1[j][1]==i) {
                arr3[k][0]=arr1[j][1];
                arr3[k][1]=arr1[j][0];
                arr3[k][2]=arr1[j][2];
                k++;
            }
        }
    }
    cout<<"Transpose:"<<endl;
    for(i=0;i<=arr3[0][2];i++) {
        cout<<arr3[i][0]<<" "<<arr3[i][1]<<" "<<arr3[i][2]<<endl;
    }
}

void add(int arr1[100][3],int arr2[100][3],int arr3[100][3]) {
    int i=1,j=1,k=1;
    if(arr1[0][0]==arr2[0][0] && arr1[0][1]==arr2[0][1]) {
        arr3[0][0]=arr1[0][0];
        arr3[0][1]=arr1[0][1];
        while(i<=arr1[0][2] && j<=arr2[0][2]) {
            if(arr1[i][0]<arr2[j][0] || (arr1[i][0]==arr2[j][0] && arr1[i][1]<arr2[j][1])) {
                arr3[k][0]=arr1[i][0];
                arr3[k][1]=arr1[i][1];
                arr3[k][2]=arr1[i][2];
                i++;k++;
            }
            else if(arr2[j][0]<arr1[i][0] || (arr1[i][0]==arr2[j][0] && arr2[j][1]<arr1[i][1])) {
                arr3[k][0]=arr2[j][0];
                arr3[k][1]=arr2[j][1];
                arr3[k][2]=arr2[j][2];
                j++;k++;
            }
            else {
                arr3[k][0]=arr1[i][0];
                arr3[k][1]=arr1[i][1];
                arr3[k][2]=arr1[i][2]+arr2[j][2];
                i++;j++;k++;
            }
        }
        while(i<=arr1[0][2]) {
            arr3[k][0]=arr1[i][0];
            arr3[k][1]=arr1[i][1];
            arr3[k][2]=arr1[i][2];
            i++;k++;
        }
        while(j<=arr2[0][2]) {
            arr3[k][0]=arr2[j][0];
            arr3[k][1]=arr2[j][1];
            arr3[k][2]=arr2[j][2];
            j++;k++;
        }
        arr3[0][2]=k-1;
        cout<<"Addition:"<<endl;
        for(i=0;i<=arr3[0][2];i++) {
            cout<<arr3[i][0]<<" "<<arr3[i][1]<<" "<<arr3[i][2]<<endl;
        }
    }
    else {
        cout<<"Addition not possible"<<endl;
    }
}

void multiply(int arr1[100][3],int arr2[100][3],int arr3[100][3]) {
    int i,j,k,l,m=1;
    int temp[100][3];
    transpose(arr2,temp);
    arr3[0][0]=arr1[0][0];
    arr3[0][1]=arr2[0][1];
    for(i=0;i<arr1[0][0];i++) {
        for(j=0;j<arr2[0][1];j++) {
            int sum=0;
            for(k=1;k<=arr1[0][2];k++) {
                if(arr1[k][0]==i) {
                    for(l=1;l<=temp[0][2];l++) {
                        if(temp[l][0]==j && temp[l][1]==arr1[k][1]) {
                            sum+=arr1[k][2]*temp[l][2];
                        }
                    }
                }
            }
            if(sum!=0) {
                arr3[m][0]=i;
                arr3[m][1]=j;
                arr3[m][2]=sum;
                m++;
            }
        }
    }
    arr3[0][2]=m-1;
    cout<<"Multiplication:"<<endl;
    for(i=0;i<=arr3[0][2];i++) {
        cout<<arr3[i][0]<<" "<<arr3[i][1]<<" "<<arr3[i][2]<<endl;
    }
}

int main() {
    int arr1[100][3] = {
        {3,3,3},  
        {0,0,5},
        {1,1,8},
        {2,2,10}
    };

    int arr2[100][3] = {
        {3,3,3}, 
        {0,1,2},
        {1,2,4},
        {2,0,6}
    };

    int arr3[100][3];

    transpose(arr1,arr3);
    add(arr1,arr2,arr3);
    multiply(arr1,arr2,arr3);

    return 0;
}
