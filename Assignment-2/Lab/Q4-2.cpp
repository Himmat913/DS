#include <iostream>
using namespace std;

int main() {
   string str;
   cout<<"Enter the string : "<<endl;
   getline(cin,str);
   
   int n = str.length();

   for(int i=0; i<n/2; i++) {
    char temp = str[i];
    str[i] = str[n-i-1];
    str[n-i-1] = temp;
   }

   cout<<"Reversed array is : "<<str<<endl;


   return 0;
}