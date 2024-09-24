#include <iostream>
using namespace std;

int main(void){
    int n, ar[1001], dp[1001], max=1;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i];

        dp[i] = ar[i];
        for(int j=0; j<i; j++){
            if(ar[i]>ar[j]){
                dp[i] += ar[j];
				
                if(max < dp[i]) max = dp[i]; 
            }
        }    
        cout <<ar[i];    
    }

    cout << max;
    return 0;
}