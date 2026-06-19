#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, m, l, limit_v, d[N], v[N], a[N], p[N];
int ans1, ans2;
int det[N];
vector<int> aa[N];
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T-- > 0) {
        ans1 = 0;
        ans2 = 0;
        cin >> n >> m >> l >> limit_v;
        for (int i = 0; i < n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            double startPlace = -1, endPlace = -1;
            bool includeStart = false, includeEnd = false;
            if (a[i] < 0) {
                if (v[i] > limit_v) {
                    includeStart = true;
                    startPlace = d[i];
                    double newEnd = d[i] + (v[i] * v[i] - limit_v * limit_v) * 1.0 / -a[i] / 2;
                    if (newEnd > l) {
                        endPlace = l;
                        includeEnd = true;
                    } else {
                        endPlace = newEnd;
                        includeEnd = false;
                    }
                } else {
                    startPlace = 0.0;
                    endPlace = 0.0;
                }
            } else if (a[i] == 0) {
                if (v[i] > limit_v) {
                    includeStart = true;
                    includeEnd = true;
                    startPlace = d[i];
                    endPlace = l;
                } else {
                    startPlace = 0.0;
                    endPlace = 0.0;
                }
            } else {
                if (v[i] >= limit_v) {
                    if (v[i] >= limit_v) {
                        includeStart = false;
                    } else {
                        includeStart = true;
                    }
                    startPlace = d[i];
                    endPlace = l;
                } else {
                    includeStart = false;
                    startPlace = d[i] + (limit_v * limit_v - v[i] * v[i]) * 1.0 / a[i] / 2;
                    endPlace = l;
                }
                includeEnd = true;
            }
//            cout << startPlace << " ~ " << endPlace << endl;
//            bool detected = false;
//            for (int j = 0; j < m; j++) {
//                if (p[j] >= startPlace - includeStart && p[j] <= endPlace - includeEnd) {
//                    detected = true;
//                    break;
//                }
//            }
            int x, y;
            if (includeStart) {
                x = lower_bound(&p[0], &p[m], startPlace) - p;
            } else {
                x = upper_bound(&p[0], &p[m], startPlace) - p;
            }
            if (includeEnd) {
                y = upper_bound(&p[0], &p[m], endPlace) - p;
            } else {
                y = lower_bound(&p[0], &p[m], endPlace) - p;
            }
//            if (detected) {
            det[i] = y - x;
            if (x != y) {
                ans1++;
            }
            for (int j = x; j < y; j++) {
                aa[j].push_back(i);
            }
//            cout << endl;
        }
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            if (aa[i].size() != 0)
                q.push({ -aa[i].size(), i});
//            cout << aa[i].size() << " ";
        }
//        cout << endl;
//        for (int i = 0; i < n; i++) {
//            cout << det[i] << " ";
//        }
//        cout << endl;
        while (!q.empty()) {
            auto i = q.top();
            q.pop();
//            cout << i.first << " " << i.second << endl;
            bool canDecrease = true;
            for (auto j : aa[i.second]) {
//                cout << det[j] << " ";
                if (det[j] == 1) {
                    canDecrease = false;
                    break;
                }
            }
//            cout << canDecrease;
            if (canDecrease) {
                for (auto j : aa[i.second]) {
                    det[j]--;
                }
            } else {
                ans2++;
            }
//            cout << endl;
        }
        cout << ans1 << " " << m - ans2 << '\n';
        for (int i = 0; i < m; i++) {
            aa[i].clear();
        }
    }
    return 0;
}

