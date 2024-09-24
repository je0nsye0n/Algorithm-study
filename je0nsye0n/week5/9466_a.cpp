#include<iostream>
#include<vector>

using namespace std;

int cnt, T, num, *ar = nullptr;
vector<bool> isVisited;

void solve(int idx) {
    int cur = idx;
    while (!isVisited[cur - 1]) {  
        isVisited[cur - 1] = true;  // Mark current node as visited
        cur = ar[cur - 1];  // Move to the next element in the sequence
    }

    cnt++;  // Increment the count for each cycle found
}

int main(void) {

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> num;
        if (num < 2 || num > 100000) return 0;

        ar = new int[num];
        isVisited.assign(num, false);  // Reset visited array for each test case

        for (int i = 0; i < num; i++)
            cin >> ar[i];

        cnt = 0;

        // Apply the solve function for each element that has not been visited
        for (int i = 0; i < num; i++) {
            if (!isVisited[i]) {
                solve(i + 1);  // Call solve for each unvisited index
            }
        }

        cout << cnt << endl;

        delete[] ar;
    }

    return 0;
}
