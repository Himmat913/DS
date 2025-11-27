#include <iostream>
using namespace std;

void heapifyMax(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;

    if(r < n && arr[r] > arr[largest])
        largest = r;

    if(largest != i){
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapifyMax(arr, n, largest);
    }
}

void heapSortIncreasing(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    for(int i = n - 1; i >= 0; i--){
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapifyMax(arr, i, 0);
    }
}

void heapifyMin(int arr[], int n, int i){
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] < arr[smallest])
        smallest = l;

    if(r < n && arr[r] < arr[smallest])
        smallest = r;

    if(smallest != i){
        int t = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = t;
        heapifyMin(arr, n, smallest);
    }
}

void heapSortDecreasing(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for(int i = n - 1; i >= 0; i--){
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapifyMin(arr, i, 0);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    int arr1[] = {12, 3, 17, 8, 25, 1, 9};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    heapSortIncreasing(arr1, n1);
    cout << "Increasing order: ";
    printArray(arr1, n1);

    int arr2[] = {12, 3, 17, 8, 25, 1, 9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    heapSortDecreasing(arr2, n2);
    cout << "Decreasing order: ";
    printArray(arr2, n2);

    return 0;
}
