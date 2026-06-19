#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

struct Car {
    int d, v, a;
} s[N];

int T, n, m, l, v, p[N];
int t[N], mt;

bool check(int d, int v0, int a) {
    if(a == 0) {
        if(v0 <= v) return false;
        else
            if(p[m] >= d) return true;
            else return false;
    } else if(a < 0) {
        if(v0 <= v) return false;
        double s = d + (v * v - v0 * v0) * 1.0 / (2 * a);
        int id = lower_bound(p + 1, p + m + 1, d) - p;
        if(p[id] <= s) return true;
        else return false;
    } else {
        if(v0 > v) {
            if(p[m] >= d) return true;
            else return false;
        } else {
            double s = d + (v * v - v0 * v0) * 1.0 / (2 * a);
            if(p[m] >= s) return true;
            else return false;
        }
    }
}

int work() {
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        if(check(s[i].d, s[i].v, s[i].a) == true)
            res++;
    }
    return res;
}

bool check2(int i, int tmp) {
    int temp = p[i];
    for(int j = i; j <= m; ++j)
        p[j] = p[j + 1];
    m--;
    if(work() == tmp) return true;
    else {
        m++;
        for(int j = m; j > i; --j)
            p[j] = p[j - 1];
        p[i] = temp;
        return false;
    }
}

void solve() {
    cin >> n >> m >> l >> v;
    for(int i = 1; i <= n; ++i) cin >> s[i].d >> s[i].v >> s[i].a;
    for(int i = 1; i <= m; ++i) cin >> p[i];

    sort(p + 1, p + m + 1);

    int ans = 0, tmp = work(), i = 1;
    while(i <= m) {
        bool q = check2(i, tmp);
        if(q == true)
            ans++;
        else
            i++;
    }
    cout << tmp << " " << ans << endl;
}

signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--)
        solve();

    return 0;
}