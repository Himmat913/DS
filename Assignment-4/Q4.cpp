#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str = "a a b c";
    queue<char> q;
    int freq[256] = {0};

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if (c == ' ') continue;

        q.push(c);
        freq[c]++;

   
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << -1 << " ";
    }

    return 0;
}
