void solve(int idx, int cur, int number){
    if(idx == number) return;
    if(cur == number) {
        cnt ++;
        return;
    }
    solve(idx, number, ar[number-1]);
}