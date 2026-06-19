#include<bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
struct Node {
    int x, y, bombs, steps;
};
int n, m;
vector<string> grid;
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int bfs() {
    queue<Node> q;
    q.push({0, 0, 0, 0});
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(30, false)));
    visited[0][0][0] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (current.x == n-1 && current.y == m-1) {
            return current.steps;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i], ny = current.y + dy[i];
            if (isValid(nx, ny)) {
                int newBombs = grid[nx][ny] == '$' ? current.bombs + 1 : current.bombs;
                if (newBombs <= 29 && !visited[nx][ny][newBombs]) {
                    visited[nx][ny][newBombs] = true;
                    q.push({nx, ny, newBombs, current.steps + 1});
                }
            }
        }
    }
    return -1;
}
int main() {
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        grid.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        int minSteps = bfs();
        if (minSteps == -1) {
            continue;
        }
        int minBombs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '$') {
                    minBombs++;
                }
            }
        }
        int maxBombs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') {
                    maxBombs++;
                }
            }
        }

        cout << maxBombs<< " " << minSteps << endl;
    }
    return 0;
}
