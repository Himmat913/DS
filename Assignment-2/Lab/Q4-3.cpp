#include <iostream>
using namespace std;

int main() {
   string str;
   cout<<"Enter the string : "<<endl;
   getline(cin,str);
   string newString;
   
   int n = str.length();

    for(int i=0; i<n; i++) {
      if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
        continue;
      } else {
            newString+=str[i];
      }
    }   

   cout<<"New array is : "<<newString<<endl;


   return 0;
}