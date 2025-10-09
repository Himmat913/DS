#include <iostream>
using namespace std;

int main() {
   string str;
   cout<<"Enter the string : ";
   getline(cin,str);
   
   int n = str.length();
   
   for(int i=0; i<n; i++) {
    for(int j=0; j<n-i-1; j++) {
        if(str[j]>str[j+1]) {
            swap(str[j],str[j+1]);
        }
    }
   }

   cout<<"Sorted string is : "<<str<<endl;


   return 0;
}