#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    
    int n, stk_n;
    string str;
    stack<int> stk;

    cin >> n;
    if(n<1 || n>10000) return 0;

    for(int i=0; i<n; i++){
        cin >> str;

        if(str == "push"){
            cin >> stk_n;
            stk.push(stk_n);
        }
        else if(str == "pop"){
            if(stk.empty()){
                cout << "-1" << endl;
            }
            else{
                cout << stk.top() << endl;
                stk.pop();
            }
        }
        else if(str == "size"){
            cout << stk.size() << endl;
        }
        else if(str == "empty"){
            if(stk.empty()) cout << "1" << endl;
            else cout << "0" << endl;
        }
        else if(str == "top"){
            if(stk.empty()) cout << "-1" << endl;
            else cout << stk.top() << endl;
        }
    }

    return 0;
}