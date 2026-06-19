#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t, n;
int a[N][4];
long long dfs(int now, int rest1, int rest2, int rest3, long long happy) {
    if (now == n+1) {
        return happy;
    }
    int x = 0, y = 0, z = 0;
    if (rest1 != 0)
        x = dfs(now+1, rest1-1, rest2, rest3, happy+a[now][1]);
    if (rest2 != 0)
        y = dfs(now+1, rest1, rest2-1, rest3, happy+a[now][2]);
    if (rest3 != 0)
        z = dfs(now+1, rest1, rest2, rest3-1, happy+a[now][3]);
    return max(max(x, y), z);
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        cout << dfs(1, n / 2, n / 2, n / 2, 0) << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
