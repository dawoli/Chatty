#include <bits/stdc++.h>

using namespace std;

const int fx[] = {0, 1, 0, -1};
const int fy[] = {1, 0, -1, 0};
int t, n, m;
char mp[1005][1005];
int st[1005][1005];
int bb[1005][1005];
bool vis[1005][1005];

int main(){
    freopen("bomb.in", "r", stdin);
    freopen("bomb.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> mp[i][j];
                vis[i][j] = 0;
                bb[i][j] = 0;
                st[i][j] = 0;
            }
        }

        queue <int> x, y;
        x.push(1); y.push(1);
        vis[1][1] = 1;
        while (!x.empty()){
            int nx = x.front(); x.pop();
            int ny = y.front(); y.pop();
            for (int i = 0; i < 4; i++){
                int dx = nx + fx[i];
                int dy = ny + fy[i];
                if (dx < 1 || dx > n) continue;
                if (dy < 1 || dy > m) continue;
                if (mp[dx][dy] == '*') continue;
                int dbb = bb[nx][ny] + (mp[dx][dy] == '$');
                int dst = st[nx][ny] + 1;
                if (!vis[dx][dy]){
                    vis[dx][dy] = true;
                    bb[dx][dy] = dbb;
                    st[dx][dy] = dst;
                    x.push(dx); y.push(dy);
                }
                else if (dbb < bb[dx][dy]){
                    bb[dx][dy] = dbb;
                    st[dx][dy] = dst;
                    x.push(dx); y.push(dy);
                }
            }
        }
        
        cout << bb[n][m] << " " << st[n][m] << "\n";
    }

    return 0;
}