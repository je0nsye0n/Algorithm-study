#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[500][500]; // 방문 여부 체크 배열
int n, m;
vector<vector<int>> graph(500, vector<int>(500)); // 2차원 벡터로 그래프 선언

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int startX, int startY) {
    int size = 0; // 현재 덩어리의 크기
    queue<pair<int, int>> q; // 좌표 (x, y)를 저장하는 큐

    q.push({startX, startY});
    visited[startX][startY] = true;
    size++; // 시작 좌표도 덩어리의 일부이므로 크기 증가

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 현재 좌표에서 상, 하, 좌, 우로 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 좌표가 범위를 벗어나지 않고, 아직 방문하지 않았으며, 1로 이루어진 부분일 때
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && graph[nx][ny] == 1) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                size++; // 연결된 1의 개수를 증가
            }
        }
    }

    return size; // 해당 덩어리의 크기 반환
}

int main(void) {
    cin >> n >> m;

    // 그래프 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int count = 0; // 1로 이루어진 덩어리의 개수
    int maxSize = 0; // 가장 큰 덩어리의 크기

    // 모든 좌표를 확인하며 1이고 방문하지 않은 곳에 대해 BFS 실행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                count++; // 새로운 덩어리 발견
                int currentSize = bfs(i, j); // BFS로 현재 덩어리의 크기 계산
                if (currentSize > maxSize) {
                    maxSize = currentSize; // 가장 큰 덩어리 크기 갱신
                }
            }
        }
    }

    // 결과 출력
    cout << count << endl; // 덩어리 개수 출력
    cout << maxSize << endl; // 가장 큰 덩어리 크기 출력

    return 0;
}
