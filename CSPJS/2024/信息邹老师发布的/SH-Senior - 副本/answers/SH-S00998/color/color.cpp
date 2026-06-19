#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;

int T, n, a[N], ans, st[N];

int calc(int pos) {
    int t = pos - 1;
    while(t > 1 && st[t] != st[pos]) t--;
    if(st[t] != st[pos]) return 0;
    else if(a[t] != a[pos]) return 0;
    else return a[pos];
}

void dfs(int pos, int sum) {
    if(pos == n + 1) {
        ans = max(ans, sum);
        return;
    }

    st[pos] = 1;
    dfs(pos + 1, sum + calc(pos));
    st[pos] = 2;
    dfs(pos + 1, sum + calc(pos));
    st[pos] = 0;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    memset(st, 0, sizeof(st));
    ans = 0;
    dfs(1, 0);

    cout << ans << endl;
}

signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--)
        solve();

    return 0;
}