#include <iostream>
#include <cctype> 
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    cout << "Lowercase: " << char(tolower(ch)) << endl;

    return 0;
}
