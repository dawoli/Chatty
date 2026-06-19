#include <bits/extc++.h>

using namespace std;
namespace pbds = __gnu_pbds;

namespace {
    ifstream fin("club.in");
    ofstream fout("club.out");

    const int N = 1e5 + 5;

    int t, n, ans, a[3];
    pbds::priority_queue<pair<int, int>, greater<pair<int, int>>> q[3];

    void solve() {
        fin >> n, ans = 0;
        for (int i = 0; i < 3; q[i++].clear());
        for (int i = 0, mx, md, k; i < n; i++) {
            mx = md = k = 0;
            for (int j = 0; j < 3; fin >> a[j], a[j] < mx ? md = min(md, mx - a[j]) : (md = a[j] - mx, mx = a[j], k = j), j++);
            q[k].push({md, mx}), ans += mx;
            if (q[k].size() > n >> 1) {
                auto [d, x] = q[k].top();
                ans -= d, q[k].pop();
            }
        }
        fout << ans << '\n';
    }
}

int main() {
    for (fin >> t; t--; solve());
}