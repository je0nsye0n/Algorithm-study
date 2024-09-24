#include <iostream>
using namespace std;

int N, K;
long dp[201][201];

int main()
{
    cin >> N >> K;

    dp[0][0] = 1;

    for (int i=0;i<=K;i++)
        dp[1][i] = i;
    
    for (int i=2;i<=N;i++)
        for (int j=1;j<=K;j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        

    cout << dp[K][N];

    return 0;
}




