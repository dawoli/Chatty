#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n, m, t, x, y, flimit, cntedge;
long long z, ans, cur;

int f[10009], ptr[19];

long long cs[19], wos[19][10009], idw[19][10009];
int u[2000009], v[2000009], id[2000009];
long long w[2000009];

int find(int x) {
    return (f[x] == x) ? x : (f[x] = find(f[x]));
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %lld", u + i, v + i, w + i);
        id[i] = i;
    }
    sort(id + 1, id + m + 1, [](const int& a, const int& b) {
        return w[a] < w[b];
    });
    for(int i = 1; i <= t; i++) {
        scanf("%lld", cs + i);
        for(int j = 1; j <= n; j++) {
            scanf("%lld", wos[i] + j);
            idw[i][j] = j;
        }
        sort(idw[i] + 1, idw[i] + n + 1, [&](const int& a, const int& b) {
            return wos[i][a] < wos[i][b];
        });
    }
    ans = inf;
    for(int i = 0; i < (1 << t); i++) {
        cur = 0;
        for(int j = 1; j <= n + t; j++) {
            f[j] = j;
        }
        ptr[0] = 1;
        flimit = n - 1;
        for(int j = 1; j <= t; j++) {
            ptr[j] = 1;
            if((i >> j - 1) & 1) {
                flimit++;
                cur += cs[j];
            }
        }
        cntedge = 0;
        while(cntedge < flimit) {
            int ptrname = -1;
            int curx = -1;
            int cury = -1;
            long long curz = inf;
            if(ptr[0] <= m && curz > w[id[ptr[0]]]) {
                curz = w[id[ptr[0]]];
                curx = u[id[ptr[0]]];
                cury = v[id[ptr[0]]];
                ptrname = 0;
            }
            for(int j = 1; j <= t; j++) {
                if((i >> j - 1) & 1) {
                    if(ptr[j] <= n && curz > wos[j][idw[j][ptr[j]]]) {
                        curz = wos[j][idw[j][ptr[j]]];
                        curx = n + j;
                        cury = idw[j][ptr[j]];
                        ptrname = j;
                    }
                }
            }
            if(ptrname == -1)
                break;
            ptr[ptrname]++;
            curx = find(curx);
            cury = find(cury);
            if(curx == cury)
                continue;
            f[curx] = cury;
            cur += curz;
            cntedge++;
        }
        ans = min(ans, cur);
    }
    printf("%lld\n", ans);
    return 0;
}