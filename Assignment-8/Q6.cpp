#include <iostream>
using namespace std;

class PriorityQueue{
public:
    int arr[100];
    int size;

    PriorityQueue(){
        size = 0;
    }

    int parent(int i) { 
        return (i - 1) / 2; 
    }

    int leftChild(int i) { 
        return 2 * i + 1; 
    }

    int rightChild(int i) { 
        return 2 * i + 2; 
    }

    void shiftUp(int i)  {
        while(i > 0 && arr[parent(i)] < arr[i]){
            int t = arr[parent(i)];
            arr[parent(i)] = arr[i];
            arr[i] = t;
            i = parent(i);
        }
    }

    void shiftDown(int i){
        int maxIndex = i;

        int l = leftChild(i);
        if(l < size && arr[l] > arr[maxIndex])
            maxIndex = l;

        int r = rightChild(i);
        if(r < size && arr[r] > arr[maxIndex])
            maxIndex = r;

        if(maxIndex != i){
            int t = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = t;
            shiftDown(maxIndex);
        }
    }

    void insert(int val){
        arr[size] = val;
        size++;
        shiftUp(size - 1);
    }

    int pop(){
        if(size == 0)
            return -1;

        int result = arr[0];
        arr[0] = arr[size - 1];
        size--;
        shiftDown(0);
        return result;
    }

    int getMax(){
        return size == 0 ? -1 : arr[0];
    }

    void print(){
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main(){
    PriorityQueue pq;

    pq.insert(45);
    pq.insert(20);
    pq.insert(14);
    pq.insert(12);
    pq.insert(31);
    pq.insert(7);
    pq.insert(11);
    pq.insert(13);
    pq.insert(7);

    cout << "Priority Queue after inserts: ";
    pq.print();

    cout << "Current max element: " << pq.getMax() << "\n";

    pq.pop();
    cout << "Priority Queue after extracting max: ";
    pq.print();

    return 0;
}
