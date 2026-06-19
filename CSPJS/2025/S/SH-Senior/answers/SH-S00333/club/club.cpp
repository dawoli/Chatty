// 最多只有一个部门最喜欢人数超过n/2，把这个部门的人分出去，留下n/2，分出去的人显然小于n/2，填不满别的部门
// 因此先按照最喜欢归属，并且记录分流到其余两个部门的减少程度
// 根据减小程度最小排序即可

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#define FILE_IO "club"
#ifdef FILE_IO
ifstream fin(FILE_IO ".in");
ofstream fout(FILE_IO ".out");
#define cin fin
#define cout fout
#endif

#define int long long

#define rep(a, b, c) for (int a = (b), _ = (c); a <= _; a++)
#define rrep(a, b, c) for (int a = (b), _ = (c); a >= _; a--)

const int N = 1e5 + 5;
const int INF = 1e9;

int n;
int tmp[4];
priority_queue<int> que[4];

inline void solve() {
    int ans = 0;
    rep(i, 1, 3) {
        tmp[i] = 0;
        while (!que[i].empty()) que[i].pop();
    }
    cin >> n;
    rep(i, 1, n) {
        int mai = 0, val = -INF;
        rep(j, 1, 3) {
            cin >> tmp[j];
            if (tmp[mai] <= tmp[j]) mai = j;
        }
        rep(j, 1, 3) {
            if (j == mai) continue;
            val = max(val, tmp[j] - tmp[mai]);
        }
        ans += tmp[mai];
        que[mai].push(val);
    }
    // cout << ans << endl;
    rep(i, 1, 3) {
        while (que[i].size() > n / 2) {
            // cout << que[i].size() << " " << (n / 2) << " " << i << endl;
            ans += que[i].top();
            que[i].pop();
        }
    }
    cout << ans << "\n";
}

signed main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}