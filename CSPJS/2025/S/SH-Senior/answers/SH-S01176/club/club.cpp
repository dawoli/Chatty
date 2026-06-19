#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 60;
int t, n, a[N][4], ans;
unordered_map<int, unordered_map<int, unordered_map<int, int>>> f;
// int cnt[4], sum[4];
// struct member {
//     struct node {
//         int val, type;
//         bool operator<(const node& n) {return val > n.val;}
//     } b[4];
//     int mx;
//     bool operator<(const member& m) {return mx > m.mx;};
// } a[N];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t; while (t--) {
        cin >> n;
        // for (int j = 1; j <= 3; j++) cnt[j] = sum[j] = 0;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= 3; j++)
        //         cin >> a[i].b[j].val, a[i].b[j].type = j;
        //     sort(a[i].b + 1, a[i].b + 4), a[i].mx = a[i].b[1].val + a[i].b[2].val + a[i].b[3].val;
        // }
        // sort(a + 1, a + n + 1);
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= 3; j++) cerr<<a[i].b[j].val<<" "<<a[i].b[j].type<<",\n"[j==3];
        //     for (int j = 1; j <= 3; j++) 
        //         if (cnt[a[i].b[j].type] < n / 2) {
        //             cnt[a[i].b[j].type]++, sum[a[i].b[j].type] += a[i].b[j].val;
        //             break;
        //         }
        // }
        // cout << sum[1] + sum[2] + sum[3] << endl; cerr<<endl;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++) cin >> a[i][j];
        f.clear(), ans = 0;
        for (int i = 1; i <= n; i++)
            // for (int j = 0; j <= min(i, n / 2); j++)
            //     for (int k = 0; k <= min(i - j, n / 2); k++) {
            //         int l = i - j - k;cerr<<"{"<<i<<","<<j<<","<<k<<","<<l<<"}";
            //         if (0 <= l && l <= n / 2)
            //             f[i][j][k][l] = max((j?f[i-1][j-1][k][l]+a[i][1]:0),
            //                 max((k?f[i-1][j][k-1][l]+a[i][2]:0),
            //                     (l?f[i-1][j][k][l-1]+a[i][3]:0)));
            //     }
            for (int j = min(i, n / 2); j >= 0; j--)
                for (int k = min(i - j, n / 2); k >= 0; k--) {
                    int l = i - j - k; if (0 <= l && l <= n / 2)
                    //for (int l = min(i - j - k, n / 2); l >= 0; l--)
                        f[j][k][l] = max(f[j][k][l],
                            max(j ? f[j - 1][k][l] + a[i][1] : 0,
                            max(k ? f[j][k - 1][l] + a[i][2] : 0,
                                l ? f[j][k][l - 1] + a[i][3] : 0)));
                }
        for (int j = 0; j <= n / 2; j++)
            for (int k = 0; k <= n / 2; k++) {
                int l = n - j - k;
                if (0 <= l && l <= n / 2)
                    ans = max(ans, f[j][k][l]);
            }
        cout << ans << endl;
    }
    return 0;
}
