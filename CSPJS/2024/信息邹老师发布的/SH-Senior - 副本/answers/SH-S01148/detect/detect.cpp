#include <iostream>
#include <set>
#define CARS_MAX 10
#define DETECTORS_MAX 10
using namespace std;
int T, n, m, L, V, c, deleted = 0, max_del = 0;
int cars_overspeed_start[CARS_MAX], cars_overspeed_end[CARS_MAX];
int p[DETECTORS_MAX], cur_del[DETECTORS_MAX];
bool cur_del_det[DETECTORS_MAX];
set<int> car_judge[CARS_MAX];
int ceil_div(int a, int b) {
    return (a % b == 0) ? (a / b) : (a / b + 1);
}
bool judge(int i, int j) {
    return cars_overspeed_end[j] > p[i] && p[i] >= cars_overspeed_start[j];
}
bool check() {
    for (int j = 0; j < n; j++) {
        if (car_judge[j].empty())
            continue;
        bool ok = false;
        for (set<int>::iterator it = car_judge[j].begin(); it != car_judge[j].end(); it++)
            if (!cur_del_det[*it]) {
                ok = true;
                break;
            }
        if (ok == false)
            return false;
    }
    return true;
}
void dfs() {
    if (deleted > max_del)
        max_del = deleted;
    for (int i = 0; i < m; i++) {
        if (cur_del_det[i])
            continue;
        cur_del_det[i] = true;
        if (!check()) {
            cur_del_det[i] = false;
            continue;
        }
        cur_del[deleted++] = i;
        dfs();
        deleted--;
        cur_del_det[i] = false;
    }
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    for (int _t = 0; _t < T; _t++) {
        c = 0;
        cin >> n >> m >> L >> V;
        long long Vsq = (long long) V * V;
        for (int i = 0; i < n; i++) {
            long long d, v, a;
            cin >> d >> v >> a;
            car_judge[i].clear();
            if (a == 0) {
                if (v > V)
                    cars_overspeed_start[i] = d,
                    cars_overspeed_end[i] = L + 1;
                else
                    cars_overspeed_start[i] =
                    cars_overspeed_end[i] = d;
            } else {
                if (a > 0)
                    cars_overspeed_start[i] = (Vsq - (long long) v * v) / (a * 2LL) + d + 1,
                    cars_overspeed_end[i] = L + 1;
                else
                    cars_overspeed_start[i] = d,
                    cars_overspeed_end[i] = ceil_div(Vsq - (long long) v * v, a * 2LL) + d;
            }
        }
        for (int i = 0; i < m; i++) {
            cur_del_det[i] = false;
            cin >> p[i];
            for (int j = 0; j < n; j++)
                    if (judge(i, j))
                        car_judge[j].insert(i);
        }
        for (int i = 0; i < n; i++)
            if (car_judge[i].size())
                c++;
        dfs();
        cout << c << ' ' << max_del << endl;
    }
    return 0;
}
