#include<bits/stdc++.h>
using namespace std;

struct sta {
    int x, y, d;
} s;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m, k;
char a[1005][1005];
bool vis[1005][1005];
int ans;

void upd() {
    int nx = s.x + dx[s.d], ny = s.y + dy[s.d];
    if(1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == '.')
        s = {nx, ny, s.d}, vis[nx][ny] = 1;
    else s = {s.x, s.y, (s.d + 1) % 4};
}

void Main() {
    ans = 0;
    memset(vis, 0, sizeof vis);
    cin >> n >> m >> k;
    cin >> s.x >> s.y >> s.d;
    vis[s.x][s.y] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= k; i++)
        upd();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(vis[i][j]) ans++;
    cout << ans << endl;
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int Q;
    cin >> Q;
    while(Q--) Main();
    return 0;
}
