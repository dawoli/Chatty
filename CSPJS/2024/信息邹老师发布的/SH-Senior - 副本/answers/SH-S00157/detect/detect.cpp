#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
int rd[1000010], ch[1000010], sum[1000010], p[100010], d[100010], v[100010], a[100010], flg[100010], id[100010], t, n, m, L, V, tot;
pair<int, int> sg[100010];
double calc(int v, int a, int s) {
	if (v * v + 2 * a * s < 0) return 0;
	return sqrt(v * v + 2 * a * s);
}
bool cmp(pair<int, int> a1, pair<int, int> a2) {
	return a1.second < a2.second;
}
int tr[4000010];
void build(int p, int l, int r) {
	if (l == r) {
		tr[p] = 0;
	} else {
		int mid = (l + r) / 2;
		build(2 * p, l, mid);
		build(2 * p + 1, mid + 1, r);
		tr[p] = tr[2 * p] + tr[2 * p + 1];
	}
}
void add(int p, int l, int r, int k, int d) {
	if (l == r) {
		tr[p] += d;
	} else {
		int mid = (l + r) / 2;
		if (k <= mid) {
			add(2 * p, l, mid, k, d);
		} else {
			add(2 * p + 1, mid + 1, r, k, d);
		}
		tr[p] = tr[2 * p] + tr[2 * p + 1];
	}
}
int query(int p, int l, int r, int cl, int cr) {
	if (l > cr || r < cl) {
		return 0;
	} else if (l >= cl && r <= cr) {
		return tr[p];
	} else {
		int mid = (l + r) / 2;
		return query(2 * p, l, mid, cl, cr) + query(2 * p + 1, mid + 1, r, cl, cr);
	}
}
bool calc(int l, int r) {
	int val2 = sum[r], val1;
	if (l == 0) {
		val1 = 0;
	} else {
		val1 = sum[l - 1];
	}
	return (val2 - val1) != 0;
}
void cor() {
	rep (i, 1, n) {
		flg[i] = 0;
	}
	rep (i, 0, L) {
		rd[i] = 0;
		ch[i] = 0;
	}
	rep (i, 1, m) {
		rd[p[i]] = 1;
	}
	int cnt = 0, res = 0;
	tot = 0;
	sum[0] = rd[0];
	rep (i, 1, L) {
		sum[i] = sum[i - 1] + rd[i];
	}
	rep (i, 1, n) {
		if (a[i] == 0) {
			if (v[i] > V) {
				if (!calc(d[i], L)) continue;
				cnt++;
				id[i] = ++tot;
				sg[id[i]].first = d[i];
				sg[id[i]].second = L;
			}
		} else if (a[i] > 0) {
			if (v[i] > V) {
				if (!calc(d[i], L)) continue;
				cnt++;
				id[i] = ++tot;
				sg[id[i]].first = d[i];
				sg[id[i]].second = L;
			} else {
				double t = (V - v[i]) * 1.0 / a[i];
				double s = v[i] * t + 0.5 * a[i] * t * t + d[i];
				if (s <= L) {
					int di = ceil(s);
					if (di == floor(s)) {
						di++;
					}
					if (!calc(di, L)) continue;
					cnt++;
					id[i] = ++tot;
					sg[id[i]].first = di;
					sg[id[i]].second = L;
				}
			}
		} else {
			if (v[i] > V) {
				double t = (v[i] - V) * 1.0 / -a[i];
				double s = v[i] * t + 0.5 * a[i] * t * t + d[i];
				int di = floor(s);
				if (di == ceil(s)) {
					di--;
				}
				if (!calc(d[i], min(di, L))) continue;
				cnt++;
				id[i] = ++tot;
				sg[id[i]].first = d[i];
				sg[id[i]].second = min(di, L);
			}
		}
	}
	sort(sg + 1, sg + tot + 1, cmp);
	build (1, 0, L);
	rep (i, 1, tot) {
		int flag = 0;
		if (query(1, 0, L, sg[i].first, sg[i].second) != 0) continue;
		int l = sg[i].first, r = sg[i].second;
		while (l <= r) {
			int mid = (l + r) / 2;
			int val2 = sum[sg[i].second], val1;
			if (mid == 0) {
				val1 = 0;
			} else {
				val1 = sum[mid - 1];
			}
			if ((val2 - val1) > 0) {
				flag = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		res++;
		ch[flag] = 1;
		add(1, 0, L, flag, 1);
	}
	cout << cnt << " " << m - res << "\n";
}
void bf() {
	rep (i, 1, n) {
		flg[i] = 0;
	}
	rep (i, 0, L) {
		rd[i] = 0;
		ch[i] = 0;
	}
	int cnt = 0, res = 0;
	tot = 0;
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (d[i] > p[j]) {
				continue;
			}
			double spd = calc(v[i], a[i], p[j] - d[i]);
			if (spd > V) {
				if (!flg[i]) {
					cnt++;
					id[i] = ++tot;
					sg[id[i]].first = p[j];
				}
				flg[i] = 1;
				rd[p[j]] = 1;
				sg[id[i]].second = p[j];
			}
		}
	}
	sort(sg + 1, sg + tot + 1, cmp);
	rep (i, 1, tot) {
		int flag = 0;
		rep (j, sg[i].first, sg[i].second) {
			if (ch[j] == 1) {
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		per (j, sg[i].second, sg[i].first) {
			if (rd[j] == 1) {
				flag = j;
				break;
			}
		}
		res++;
		ch[flag] = 1;
	}
	cout << cnt << " " << m - res << "\n";
}
void solve() {
	cin >> n >> m >> L >> V;
	rep (i, 1, n) {
		cin >> d[i] >> v[i] >> a[i];
	}
	rep (i, 1, m) {
		cin >> p[i];
	}
	if (n <= 3000) {
		bf();
//		cor();
	} else {
		cor();
	}
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);
	cin >> t;
	while (t--) {
		solve();
	}
}
