#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAXN = 5e5+7;
int a[MAXN], xorsum[MAXN];
// string re(string s) {
//     for (int i = 0, j = s.size()-1; i < j; i++) {
//         swap(s[i], s[j]);
//     }
//     return s;
// }
// string toBinary(int n) {
//     string ans;
//     while (n) {
//         ans += n%2 + '0';
//         n >>= 1;
//     }
//     return re(ans);
// }
// int ans = 0;
// void dfs(int id, int ct) {
//     if (id == m) {
//         ans = max(ans, ct);
//         return 0;
//     }
//     int cur = id;
//     while (id < m && cobb[cur].second >= cobb[id].first) {
//         ++id;
//     }
//     for (int i = id; i <= n; i++) {
//         dfs(i, )
//     }
// }
int main() {
    // cout << toBinary(2);
    // return 0;
    // cout << (3 ^ 2);
    // return 0;
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pii> cobb;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        xorsum[i] = xorsum[i-1] ^ a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == k) cobb.push_back({i, i});
        for (int j = i+1; j <= n; j++) {
            if ((xorsum[j] ^ xorsum[i-1]) == k) {
                cobb.push_back({i, j});
                break;
            }
        }
    }
    // for (auto x : cobb) cout << x.first << ' ' << x.second << endl;
    // return 0;
    int m = cobb.size();
    // puts("");
    int ans = 0;
    for (int id = 0; id < m; id++) {
        vector<pii> vc;
        int pre = id, ct = 0;
        while (1) {
            int minid = 0, minval = INT_MAX;
            bool falg = 0;
            for (int i = id+1; i < m; i++) {
                if (cobb[i].first > cobb[id].second && cobb[i].second < minval) {
                    minval = cobb[i].second;
                    falg = 1;
                    minid = i;
                }
            }
            if (!falg) break;
            ++ct;
            id = minid;
            vc.push_back((make_pair(cobb[id].first, cobb[id].second)));
        }
        id = pre;
        ans = max(ans, ct);
        // if (ct == 107) {
        //     for (auto x : vc) cout << x.first << ' ' << x.second << endl;
        // }
    }
    printf("%d", ans+1);
    return 0;
}