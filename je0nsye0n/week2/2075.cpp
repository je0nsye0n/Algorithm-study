#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    cin.tie(), ios_base::sync_with_stdio(false);
    int n, temp;
    cin>>n;
    
    priority_queue<int,vector<int>,greater<int> > pq;
    
    for(int i = 0; i < n*n; i++){
        cin>>temp;
        pq.push(temp);

        if(pq.size()> n){
            pq.pop();
        }
    }
    
    cout<<pq.top()<<"\n";
}