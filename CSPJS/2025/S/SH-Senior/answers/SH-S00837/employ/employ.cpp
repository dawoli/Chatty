#include <bits/extc++.h>

using namespace std;

namespace {
    ifstream fin("employ.in");
    ofstream fout("employ.out");

    const int N = 15;

    int n, m, ans, p[N], c[N];
    string s;

    bool check() {
        int cnt = 0;
        for (int i = 0; i < n; cnt += (cnt >= c[p[i]] || s[i] == '0'), i++);
        return n - cnt >= m;
    }

    void solve() {
        fin >> n >> m >> s, iota(p, p + n, 0);
        for (int i = 0; i < n; fin >> c[i++]);
        do ans += check();
        while (next_permutation(p, p + n));
        fout << ans << '\n';
    }
}

int main() {
    solve();
}