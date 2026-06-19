#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

struct Node {
	int l, r, st;
};

bool cmp(Node A, Node B) {
	return A.r - A.l < B.r - B.l;
}

int t;

int main()  {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n, m, len, lim, ans = 0, ans2 = 0, d[N], v[N], a[N], p[N], cnt[N];
		Node car[N] = {0};
		cin >> n >> m >> len >> lim;
		for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
		for (int i = 1; i <= m; i++) cin >> p[i];
		for (int i = 1; i <= n; i++) {
			int pos = d[i], pre = ans;
			double spd = v[i];
			for (int j = 1; j <= m; j++) {
				if (p[j] < pos) continue;
				int dis = p[j] - pos;
				if (spd * spd + 2 * a[i] * dis > lim * lim) {
					if (pre == ans) ans++;
					if (!car[i].l) car[i].l = j;
					cnt[j]++;
				} else {
					if (car[i].l && !car[i].r) car[i].r = j - 1;
				}
				pos = p[j];
				spd = sqrt(spd * spd + 2 * a[i] * dis);
				if (spd * spd + 2 * a[i] * dis <= 0) break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (car[i].l && !car[i].r) car[i].r = n;
		}
		sort(car + 1, car + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (car[i].st) continue;
			if (!car[i].l && !car[i].r) continue;
			int id, maxx = 0;
			for (int j = car[i].l; j <= car[i].r; j++) {
				if (cnt[j] > maxx) {
					maxx = cnt[j];
					id = j;
				}
			}
			for (int j = 1; j <= n; j++) {
				if (id >= car[j].l && id <= car[j].r) car[j].st = 1;
			}
			ans2++;
		}
		cout << ans << " " << n - ans2 << endl;
	}                                                        
	return 0;
}
