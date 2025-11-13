#include <iostream>
using namespace std;

//(a) Selection Sort
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minPos = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[minPos])
                minPos = j;
        int temp = arr[minPos];
        arr[minPos] = arr[i];
        arr[i] = temp;
    }
}

//(b) Insertion Sort
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

//(c) Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }    
}

//(d) Merge Sort
void mergeArray(int arr[], int si, int mid, int ei) {
    int size = ei-si+1;
    int temp[size];
    int i = si;
    int j = mid+1;
    int k = 0;

    while(i <= mid && j <=ei) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j <= ei) {
        temp[k++] = arr[j++];
    }

    for(k = 0; k < size; k++) {
        arr[si+k] = temp[k];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    } 
    int mid = si+(ei-si)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    mergeArray(arr, si, mid, ei);
}

//(e) Quick Sort
int partitionArray(int arr[], int si, int ei) {
    int pivot = arr[ei];
    int i = si-1;

    for (int j = si; j < ei; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;
    int temp = pivot;
    arr[ei] = arr[i];
    arr[i] = temp;
    return i;
}

void quickSort(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }

    int pIdx = partitionArray(arr, si, ei);
    quickSort(arr, si, pIdx-1);
    quickSort(arr, pIdx+1, ei);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[100], n, choice;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cout<< "\nChoose Sorting Method:\n";
    cout<< "1. Selection Sort\n";
    cout<< "2. Insertion Sort\n";
    cout<< "3. Bubble Sort\n";
    cout<< "4. Merge Sort\n";
    cout<< "5. Quick Sort\n";
    cout<< "Enter choice: ";
    cin>> choice;

    switch(choice) {
        case 1: selectionSort(arr, n); 
        break;
        case 2: insertionSort(arr, n); 
        break;
        case 3: bubbleSort(arr, n); 
        break;
        case 4: mergeSort(arr, 0, n-1); 
        break;
        case 5: quickSort(arr, 0, n-1); 
        break;
        default: cout<< "Invalid choice!"; 
        return 0;
    }

    cout<< "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}
