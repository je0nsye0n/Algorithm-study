#include<iostream>

using namespace std;

int cnt, T, num, *ar=nullptr;

void solve(int idx, int cur, int number){
    if(idx == number) return;
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

        ar = new int [num];
        for(int i=0; i<num; i++)
            cin >> ar[i];


        cnt=0;

        for(int i=0; i<num; i++){
            solve(i+1, i+1, ar[i]);
        }

        cout << cnt << endl;

        for(int i=0; i<num; i++)
            ar[i]=false;
        delete[] ar;
    }

    return 0;
}
