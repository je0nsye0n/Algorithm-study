#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
 
using namespace std;

vector<int> Fail(string pattern) {
	int m = pattern.length();
	vector<int> pi(m); 

	pi[0] = 0; // 그런가?
	for (int i = 0, j = 0; i < m; i++) { 
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j; 
	} 
	return pi;
}

vector<int> search(string P, string T){
    vector<int> pos, pi = Fail(P);
    int m = P.length(), n=T.length();

    for(int i=0, j=0; i<n; i++){
        while (j>0 && T[i]!=P[j])
        {
            j = pi[j-1];
        }

        if(T[i]==P[i]){
            if(j == (m-1)){
                pos.push_back(i-m+1+1);
                j=pi[j];
            }
            else j++;
        }
        
    }
    return pos;
}

int main(){
    string T, P;
    //cout << "a";
    getline(cin, T); // getline(istram&, string)
    getline(cin, P);
    cout << T;
    cout << P;
    vector<int> index = search(P, T);

    cout << index.size() << "\n";
    for(int i=0; i<index.size(); i++)
        cout << index[i] << ' ';

}