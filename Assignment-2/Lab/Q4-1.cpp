#include <iostream>
using namespace std;

int main() {
   string str1, str2;
   cout<<"Enter first string : "<<endl;
   getline(cin,str1);
   cout<<"Enter second string : "<<endl;
   getline(cin,str2);

   string added = str1 + str2;
   cout<<"The resultant string is : "<<added<<endl;

   return 0;
}