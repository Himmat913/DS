#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n){
    int start = 0, end = n-1;
    while (start < end) {
        int minPos = start;
        int maxPos = end;

        if (arr[minPos] > arr[maxPos]) {
            int temp = arr[minPos];
            arr[minPos] = arr[maxPos];
            arr[maxPos] = temp;
        }

        for (int i = start+1; i < end; i++) {
            if (arr[i] < arr[minPos]) minPos = i;
            if (arr[i] > arr[maxPos]) maxPos = i;
        }

        int temp = arr[start];
        arr[start] = arr[minPos];
        arr[minPos] = temp;

        if (maxPos == start) 
        maxPos = minPos;

        temp = arr[end];
        arr[end] = arr[maxPos];
        arr[maxPos] = temp;

        start++;
        end--;
    }
}

int main() {
    int n;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
