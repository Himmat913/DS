#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);

    int n = q.size();
    int index = 0;
    int rotations = 0;

    while (!q.empty()) {
        if (q.front() == sandwiches[index]) {
            q.pop();
            index++;
            rotations = 0;
        } else {
            int temp = q.front();
            q.pop();
            q.push(temp);
            rotations++;
        }

        if (rotations == q.size())
            return q.size();
    }

    return 0;
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    cout << countStudents(students, sandwiches);
}
