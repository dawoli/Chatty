#include <bits/stdc++.h>
using namespace std;
bool flag;
int t, n, m, k, x, y;
int l[100009];
set <int> got[200009];
vector <int> a[100009];
bool dfs(int d, int cur, int plc) {
    if(d == x) {
        if(!got[y].count(cur))
            return false;
        for(int i = plc + 1; i <= min(plc + m - 1, l[cur]); i++) {
            if(a[cur][i] == y)
                return true;
        }
        return false;
    }
    for(int i = plc + 1; i <= min(plc + m - 1, l[cur]); i++) {
        for(int ncur : got[a[cur][i]]) {
            if(ncur == cur)
                continue;
            for(int j = 0; j < l[ncur]; j++) {
                if(a[ncur][j] == a[cur][i] && dfs(d + 1, ncur, j))
                    return true;
            }
        }
    }
    return false;
}
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        for(int i = 1; i <= 2e5; i++) {
            got[i].clear();
        }
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%d", l + i);
            a[i].clear();
            for(int j = 1; j <= l[i]; j++) {
                scanf("%d", &x);
                got[x].insert(i);
                a[i].push_back(x);
            }
        }
        for(int i = 1; i <= k; i++) {
            scanf("%d %d", &x, &y);
            flag = false;
            for(int cur : got[1]) {
                for(int j = 0; j < l[cur]; j++) {
                    if(a[cur][j] == 1 && dfs(1, cur, j)) {
                        flag = true;
                        break;
                    }
                }
            }
            printf("%d\n", flag);
        }
    }
    return 0;
}