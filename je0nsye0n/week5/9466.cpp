#include<iostream>
#include <vector>

using namespace std;

int cnt, T, num;
vector<int> ar;
vector<bool> isVisited;

void check(int idx){
    int next=-1;
    isVisited[idx-1] = true;

    while(1){
        cout << "a";
        if(isVisited[idx-1] && next == (idx-1)) return;
        next = ar[idx-1]-1;
        isVisited[next] = true;
    }
}

void solve(int idx, int cur, int number){
    if(idx == number) {
        check(idx);
        return;
    };
    if(cur == number) {
        cnt ++;
        return;
    }
    solve(idx, number, ar[number-1]);
}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> num;
        if(num<2 || num>100000) return 0;

        ar.resize(num);
        isVisited.assign(num, false);

        for(int i=0; i<num; i++)
            cin >> ar[i];
            
        cnt=0;

        for(int i=0; i<num; i++){
            if(!isVisited[i]) {
                solve(i+1, i+1, ar[i]);
            }
        }

        cout << cnt << endl;

    }

    return 0;
}