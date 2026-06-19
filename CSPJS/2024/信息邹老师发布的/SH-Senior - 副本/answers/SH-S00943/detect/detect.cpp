#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int T, n, m, len, vmax, cnt;
int d[MAXN], v[MAXN], a[MAXN], p[MAXN], dif[MAXN], ans[MAXN];

int cmp(int a, int b) {
    return a > b;
}

int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int need_n = 0, x, y, z, t, tt, ttt;
    cin >> n >> m >> len >> vmax;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z; 
        if (y > vmax || z > 0) {
            // 只记可能会超速的车
            need_n++;
            d[need_n] = x;
            v[need_n] = y;
            a[need_n] = z;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
        // 维护一个差分 用于记录这个点一共记录了多少个超速
        dif[i] = 0;
    }
    dif[0] = 0;
    
    cnt = 0;

    for (int i = 1; i <= need_n; i++) {
        // 加速度为0 那么肯定是v>vmax d以后的监测点都能检测到
        if (a[i] == 0) {
            tt = lower_bound(p + 1, p + m + 1, d[i]) - p;
            if (tt >= 1 && tt <= m) {
                dif[tt]++;
                cnt++;
            }
        } 
        // 如果加速度大于0 那么在v超过vmax后的那个点开始能被检测到
        else if (a[i] > 0) {
            if (v[i] < vmax) {
// 这一行可能要调
                t = d[i] + (vmax * vmax - v[i] * v[i]) / (2 * a[i]);
                tt = lower_bound(p + 1, p + m + 1, t + 1) - p;
            }
            else if (v[i] = vmax) {
                tt = lower_bound(p + 1, p + m + 1, d[i] + 1) - p;
            } else {
                tt = lower_bound(p + 1, p + m + 1, d[i]) - p + 1;
            }
            if (tt >= 1 && tt <= m) {
                dif[tt]++;
                cnt++;
            }
        }
        // 如果加速度小于0 那么在v小于vmax后的那个点开始不能被检测到
        else {
// 这一行可能要调
            t = d[i] + (vmax * vmax - v[i] * v[i]) / (2 * a[i]);

            tt = lower_bound(p + 1, p + m + 1, d[i]) - p;
            ttt = lower_bound(p + 1, p + m + 1, t) - p;
            if (tt >= 1 && tt <= m && tt != ttt) {
                cnt++;
            }

            dif[tt]++;
            dif[ttt]--;
        }
    }
    cout << cnt << " ";

    ans[0] = 0;
    t = 0;
    for (int i = 1; i <= m; i++) {
        ans[i] = ans[i - 1] + dif[i];
    }
    sort(ans + 1, ans + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        if (cnt <= 0) break;
        cnt -= ans[i];
        t++;
    }
    cout << m - t << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
}
