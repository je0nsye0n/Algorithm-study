#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main(void){
    int n, min_num=INTMAX_MAX, max_size=0, mode, num;
    queue<int> que;

    cin >> n;
    if(n<1 || n>100000) return 0;

    for(int i=0; i<n; i++){
        cin >> mode;
        if(mode==1){
            cin >> num;
            que.push(num);
            if(que.size() > max_size){
                max_size = que.size();
                min_num = num;            
            }
            if(que.size() == max_size){
                if(num < min_num) 
                    min_num = num;
            }
        }
        else{
            if(!que.empty())
                que.pop();
        }
    }
    
    cout << max_size << " " << min_num;

    return 0;
}