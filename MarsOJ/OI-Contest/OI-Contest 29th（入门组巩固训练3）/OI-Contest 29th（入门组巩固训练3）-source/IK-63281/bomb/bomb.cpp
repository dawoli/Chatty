#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct Node {
    int x, y, step;
    bool operator<(const Node& rhs) const {
        return step > rhs.step;
    }
};

int main() {
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<string> grid(m);
        for (int i = 0; i < m; ++i) {
            cin >> grid[i];
        }

        vector<vector<int>> dist(m, vector<int>(n, -1));
        dist[0][0] = 0;
        priority_queue<Node> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            int x = cur.x, y = cur.y, step = cur.step;
            if (x == n - 1 && y == m - 1) {
                break;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[ny][nx] != '*' && dist[ny][nx] == -1) {
                    dist[ny][nx] = step + 1;
                    pq.push({nx, ny, step + 1});
                }
            }
        }

        int bombs = 0, min_steps = dist[m - 1][n - 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '$') {
                    bombs++;
                }
            }
        }

        cout << bombs << " " << min_steps << endl;
    }
    return 0;
}