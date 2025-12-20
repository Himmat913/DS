#include <iostream>
#include <stack>
using namespace std;

int main() {
       int n;
       cout << "Enter size of array: " << endl;
       cin >> n;

       int arr[1000], ans[1000];
       stack<int> s;

       for(int i=0; i<n; i++) {
          cin >> arr[i];
       }

       for(int i=0; i<n; i++) {
        while(!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        if(s.empty()) 
            ans[i] == -1;
        else
            ans[i] == s.top();

        s.push(arr[i]);    

       }

       for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
       }

       return 0;

}