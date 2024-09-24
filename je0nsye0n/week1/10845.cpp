#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void){
    int n, que_n;
    string str;
    queue<int> que;

    cin >> n;
    if(n < 1 || n > 10000) return 0;
    for(int i=0; i<n; i++){
        cin >> str;
        if(str=="push"){
            cin >> que_n;
            que.push(que_n);
        }
        else if(str=="pop"){
            if(que.empty()) cout << "-1" << endl;
            else {
                cout << que.front() << endl;
                que.pop();
            }
        }
        else if(str=="size"){
            cout << que.size() << endl;
        }
        else if(str=="empty"){
            cout<<que.empty()<<endl;
        }
        else if(str=="front"){
            if(que.empty()) cout << "-1" << endl; 
            else cout << que.front() << endl;
        }
        else if(str=="back"){
            if(que.empty()) cout << "-1" << endl; 
            else cout << que.back() << endl;
        }
    }
    return 0;
}