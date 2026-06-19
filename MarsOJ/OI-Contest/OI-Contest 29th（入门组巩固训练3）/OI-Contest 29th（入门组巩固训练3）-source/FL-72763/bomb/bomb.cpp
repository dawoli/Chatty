#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005, MAX_M = 1005, INF = 0x3f3f3f3f, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

char maze[MAX_N][MAX_M];
int dist[MAX_N][MAX_M][2];

struct State {
    int x, y, b, d;
    State(int x, int y, int b, int d) : x(x), y(y), b(b), d(d) {}
    bool operator>(const State& other) const {
        if (b != other.b) return b > other.b;
        return d > other.d;
    }
};

pair<int, int> bfs(int n, int m) {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<State, vector<State>, greater<State> > pq;
    pq.push(State(0, 0, 0, 0));
    dist[0][0][0] = dist[0][0][1] = 0;

    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y, b = cur.b, d = cur.d;

        if (x == n-1 && y == m-1) return make_pair(b, d);

        if (d > dist[x][y][1] && b >= dist[x][y][0]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || maze[nx][ny] == '*') continue;
            
            int nb = b + (maze[nx][ny] == '$');
            int nd = d + 1;

            if (nb < dist[nx][ny][0] || (nb == dist[nx][ny][0] && nd < dist[nx][ny][1])) {
                dist[nx][ny][0] = nb;
                dist[nx][ny][1] = nd;
                pq.push(State(nx, ny, nb, nd));
            }
        }
    }
    return make_pair(-1, -1);
}

int main() {
    freopen("bomb.in", "r", stdin);
    freopen("bomb.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        getchar();
        
        for (int i = 0; i < n; i++) {
            fgets(maze[i], MAX_M, stdin);
            int len = strlen(maze[i]);
            if (len > 0 && maze[i][len-1] == '\n') {
                maze[i][len-1] = '\0';
            }
        }

        pair<int, int> result = bfs(n, m);
        printf("%d %d\n", result.first, result.second);
    }
    return 0;
}
