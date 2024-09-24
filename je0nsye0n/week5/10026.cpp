#include<iostream>
#include<vector>

using namespace std;
int n;
char color[101][101];
bool visited[101][101] = {false};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, char currentColor) {
    visited[x][y] = true; 

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && color[nx][ny] == currentColor) {
            dfs(nx, ny, currentColor);
        }
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    int areaCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) { 
                dfs(i, j, color[i][j]);
                areaCount++; 
            }
        }
    }
    cout << areaCount << " ";

    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            visited[i][j]=false;
            if(color[i][j]=='R')
                color[i][j] = 'G';
        }
    }
    
    areaCount = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) { 
                dfs(i, j, color[i][j]);
                areaCount++; 
            }
        }
    }
   cout << areaCount;

    return 0;
}
