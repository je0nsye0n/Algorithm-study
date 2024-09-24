#include <iostream>
using namespace std;

int main(void){
    int n, ar[1001], dp[1001], max=1;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i];

        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(ar[i]>ar[j] && (dp[i]<dp[j]+1)){
                dp[i] = dp[j]+1; 
				
                if(max < dp[i]) 
					max = dp[i]; 
            }
        }
    }

    cout << max;
    return 0;
}