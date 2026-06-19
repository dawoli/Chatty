#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Node {
    int x[4];
    int maxx;
};
bool cmp(Node x, Node y) {
    return x.maxx > y.maxx;
}
Node a[N];
bool vis[N];
void solve() {
    int n;
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x[1] >> a[i].x[2] >> a[i].x[3];
        a[i].maxx = max({a[i].x[1], a[i].x[2], a[i].x[3]});
        sort(a[i].x + 1, a[i].x + 3, greater<int>());
    }
    int cnt[5], much = 0;
    memset(cnt, 0, sizeof(cnt));
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        /*bool id[5];
        id[1] = 0, id[2] = 0, id[3] = 0;
        for (int j = 1; j <= 3; j++) {
            if (a[i].x[j] == a[i].maxx) id[j] = 1;
        }
        int tmp1 = 0, tmp2 = 0, tmp3 = 0;
        if (id[1] == 0) tmp1 = 1;
        if (id[2] == 0) tmp2 = 1;
        if (id[3] == 0) tmp3 = 1;*/
        /*for (int j = 1; j <= 3; j++) {
            if (id[j] == 1 && cnt[j] + 1 <= n / 2) {
                much += a[i][j], cnt[j]++;
            }
        }*/
    }


}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
