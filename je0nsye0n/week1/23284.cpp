#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> 
using namespace std;

void generateSequences(int n, int num, stack<int>& s, vector<int>& sequence, vector<vector<int>>& allSequences) {
    if (num > n && s.empty()) {
        // 모든 수를 사용하고, 스택도 비었을 때, 완성된 수열을 저장
        allSequences.push_back(sequence);
        return;
    }

    // 스택에 숫자를 push하는 경우
    if (num <= n) {
        s.push(num);
        generateSequences(n, num + 1, s, sequence, allSequences);
        s.pop();  // 이전 상태로 되돌리기
    }

    // 스택에서 숫자를 pop하는 경우
    if (!s.empty()) {
        int top = s.top();
        s.pop();
        sequence.push_back(top);
        generateSequences(n, num, s, sequence, allSequences);
        sequence.pop_back();  // 이전 상태로 되돌리기
        s.push(top);  // 스택 상태 복구
    }
}

int main() {
    int n;
    cin >> n;
    stack<int> s;
    vector<int> sequence;
    vector<vector<int>> allSequences;  // 모든 수열을 저장할 벡터
    
    generateSequences(n, 1, s, sequence, allSequences);
    
    // 사전순으로 정렬
    sort(allSequences.begin(), allSequences.end());
    
    // 정렬된 수열을 출력
    for (const auto& seq : allSequences) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
