#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using LL = long long;

const LL MOD = 998244353;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    LL n, m;
    string s;
    cin >> n >> m >> s;
    vector<LL> a, p, p0;
    for (LL i = 0; i < n; i++) {
        LL x;
        cin >> x;
        a.push_back(x);
        p.push_back(i);
        p0.push_back(i);
    }
    LL cnt = 0;
    do {
        LL fail_cnt = 0;
        for (LL i = 0; i < n; i++) {
            if (s[i] == '0' || fail_cnt >= a[p[i]]) {
                fail_cnt++;
            }
        }
        cnt += (n - fail_cnt >= m);
        next_permutation(p.begin(), p.end());
    } while (p != p0);
    cout << cnt << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
