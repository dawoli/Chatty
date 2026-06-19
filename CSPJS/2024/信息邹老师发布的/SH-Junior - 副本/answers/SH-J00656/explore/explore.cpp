#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, nx, ny, cnt;
char s[1009];
bool mp[1009][1009], vst[1009][1009];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d %d %d", &n, &m, &k);
        scanf("%d %d %d", &x, &y, &d);
        for(int i = 1; i <= n; i++) {
            scanf("%s", s);
            for(int j = 1; j <= m; j++) {
                mp[i][j] = (s[j - 1] == '.');
                vst[i][j] = false;
            }
        }
        cnt = 1;
        vst[x][y] = true;
        for(int i = 1; i <= k; i++) {
            if(d == 0)
                nx = x, ny = y + 1;
            else if(d == 1)
                nx = x + 1, ny = y;
            else if(d == 2)
                nx = x, ny = y - 1;
            else
                nx = x - 1, ny = y;
            if(mp[nx][ny])
                x = nx, y = ny;
            else
                d = (d + 1) % 4;
            if(!vst[x][y])
                cnt++;
            vst[x][y] = true;
        }
        printf("%d\n", cnt);
    }
    return 0;
}