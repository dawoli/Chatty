#include <bits/stdc++.h>

using namespace std;
int t, a[200005], n, seq[2005];
long long ans, cans;
void dfs(int pos, int x) {
    seq[pos] = x;
    if(pos == n) {
        cans = 0;
        for(int i = 1; i <= n; i++) {
            int cls = -1;
            for(int j = i - 1; j >= 1; j--) {
                if(seq[j] == seq[i]) {
                    cls = a[j];
                    if(cls != a[i]) cls = 0;
                    break;
                }
            }
            if(cls != -1) cans += cls;
        }
        ans = max(cans, ans);
        return;
    } else {
        pos++;
        dfs(pos, 0);
        dfs(pos, 1);
    }
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    for(int tsc = 1; tsc <= t; tsc++) {
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if(n > 50) {
            cout << 0 << endl;
            continue;
        }
        dfs(1, 0);
        dfs(1, 1);
        cout << ans << endl;
    }
    return 0;
}
