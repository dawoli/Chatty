#include <bits/stdc++.h>
#define N 100005
#define eps 0.0000001

using namespace std;

int t, res, n, m, L, V, ans, ch[N], d[N], v[N], a[N], p[N], nxt[1000005], cnt[N];

inline double getSp(const int &v0, const int &a, const int &s) {
	return sqrt(v0 * v0 + 2 * a * s);
}

inline double getS(const int &v0, const int &a, const double &t) {
	return 1.0 * v0 * t + 0.5 * a * t;
}

struct node {
	int l, r;
	bool flag;
	bool operator < (const node &b) const {
		return l < b.l;
	}
};

vector<node> car;

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
	cin >> t;
	while (t --) {
		ans = res = 0;
		cin >> n >> m >> L >> V;
		for (int i=0; i<n; ++i) {
			cin >> d[i] >> v[i] >> a[i];
		}
		for (int i=1; i<=m; ++i) {
			cin >> p[i];
		}
		sort(p + 1, p + m + 1);
		for (int i=0, now = 1; i<=L; ++i) {
			nxt[i] = now;
			if (now != m + 1 && i == p[now]) now ++;
		}
		for (int i=0; i<n; ++i) {
			if (a[i] == 0 && (v[i] <= V || d[i] > p[m])) continue;
			if (a[i] > 0 && (d[i] > p[m] || getSp(v[i], a[i], p[m] - d[i]) < V + eps)) continue;
			if (a[i] < 0) {
				int naEst = nxt[d[i]];
				if (naEst == m + 1 || v[i] * v[i] + 2 * a[i] * (p[naEst] - d[i]) < 0 || getSp(v[i], a[i], p[naEst] - d[i]) < V + eps) continue;
			}
			ans ++;
			if (a[i] == 0) {
				car.push_back((node) {nxt[d[i]], m, true});
			} else if (a[i] > 0) {
				if (v[i] < V) car.push_back((node) {nxt[(int) (d[i] + (1.0 * V * V - v[i] * v[i]) / 2 / a[i])], m, true});
				else car.push_back((node) {nxt[d[i]], m, true});
			} else {
				car.push_back((node) {nxt[d[i]], nxt[(int) (d[i] + (1.0 * V * V - v[i] * v[i]) / 2 / a[i]) + 1] - 1, true});
			}
		}
		cout << ans << " ";
		sort(car.begin(), car.end());
		for (int i = 0; i<car.size(); ++i) {
			for (int j = car[i].l; j <= car[i].r; ++j) {
				cnt[j] ++;
			}
		}
		int tmp = 0, id;
		bool flg = true;
		while (flg) {
			flg = false;
			for (int i = 1; i <= m; ++i) {
				if (tmp < cnt[i]) {
					tmp = cnt[i];
					id = i;
					flg = true;
				}
			}
			if (!flg) break;
			res ++;
			for (int i=0; i<=car.size(); ++i) {
				if (car[i].flag && car[i].l <= id && id <= car[i].r) {
					for (int j=car[i].l; j<=car[i].r; ++j) {
						cnt[j] --;
					}
					car[i].flag = false;
				}
			}
			tmp = 0;
		}
		cout << m - res << endl;
	}
	return 0;
}
