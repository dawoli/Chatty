#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXL = 1e6 + 10;
int t, n, m, L, V;
int ndp[MAXL], qzh[MAXL];
struct CAR {
    int din, dout;
} car[MAXN];
set<int > car_p[MAXN];
double x; int y;
int p[MAXN];

// bool check(int x) {

// }

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> L >> V;
        int final = 0;
        for (int i = 1; i <= n; ++i) {
            int d, v, a;
            cin >> d >> v >> a;
            if (a == 0) {
                if (v > V) {
                    ndp[d]++;
                    car[i].din = d, car[i].dout = L;
                }
            }
            else if (a > 0) {
                if (v > V) {
                    ndp[d]++;
                    // final++;
                }
                else {
                    x = double((V * V - v * v)) / (2 * a);
                    y = int(x) + 1;
                    // cout << " # " << x << "\n";
                    ndp[d + y]++;
                    car[i].din = d + y, car[i].dout = L;
                }
            }
            else {
                a = -a;
                if (v > V) {
                    ndp[d]++;
                    car[i].din = d;
                    x = double((v * v - V * V)) / (2 * a);
                    y = int(x);
                    if (y * (2 * a) == (v * v - V * V)) {
                        ndp[d + y]--;
                        car[i].dout = d + y;
                    }
                    else {
                        ndp[d + y + 1]--;
                        car[i].dout = d + y + 1;
                    }
                }
            }
        }
        // qzh[1] = ndp[1];
        // for (int i = 2; i <= L; ++i) {
        //     qzh[i] = qzh[i - 1] + ndp[i];
        //     cout << "$ " << ndp[i] << "\n";
        // }
        for (int ip = 1; ip <= m; ++ip) {
            cin >> p[ip];
        }
        int car_num = 0;
        for (int i = 1; i <= n; ++i) {
            bool flag = 0;
            for (int j = 1; j <= m; ++j) {
                if (p[j] >= car[i].din && p[j] <= car[i].dout) {
                    flag = 1;
                    car_p[i].insert(j);
                }
            }
            if (flag) car_num++;
        }
        cout << car_num << " ";
        // int l = 0, r = m, mid = (l + r) / 2;
        // while (l < r) {
        //     if (check(mid)) l = mid;
        //     else r = mid - 1;
        //     mid = (l + r) / 2;
        // }
        // cout << l;
         int p_num = 0;
         for (int j = m; j >= 0; j--) {
             bool flag = 1;
             for (int i = 1; i <= n; ++i) {
                 if (car_p[i].find(j) != car_p[i].end() && car_p[i].size() == 1) {
                     flag = 0;
                 } 
             }
             if (flag) {
                 p_num++;
                 for (int i = 1; i <= n; ++i) {
                     car_p[i].erase(j);
                 }
             }
         }
         cout << p_num << "\n";
    }
    return 0;
}
