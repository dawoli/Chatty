#include <bits/stdc++.h>
#define rep(x, y, z) for (int x=(y); x<=(z); x++)
#define debug(x) cout << fixed << (#x) << "=" << (x) << endl;
#define line cout << endl;

using namespace std;

const int N = 1e5+5;
const double eps = 1e-6;

int n, m;
bitset<N> ot, used;
double L, V, d[N], v[N], a[N], p[N];
double l[N], r[N];

int po[N];
vector<int> lk[N];

void solve() {
	cin >> n >> m >> L >> V;
	rep(i, 0, n-1) {
		used[i] = 0;
		cin >> d[i] >> v[i] >> a[i];
	}
	rep(i, 0, m-1) {
		lk[i].clear();
		po[i] = i;
		cin >> p[i];
    }
	
	rep(i, 0, n-1) {
		ot[i] = 1;

		if (a[i] == 0) {
			if (v[i] > V) l[i] = d[i], r[i] = L;
			else ot[i] = 0;
		} else if (a[i] > 0) {
			if (v[i] > V) l[i] = d[i], r[i] = L;
			else {
				double tmp = (V*V-v[i]*v[i])/(2*a[i]);
				l[i] = d[i] + tmp + eps, r[i] = L;
				if (l[i] > L) ot[i] = 0;
			}
		} else if (a[i] < 0) {
			if (v[i] <= V) ot[i] = 0;
			else {
				double tmp = (V*V-v[i]*v[i])/(2*a[i]);
				l[i] = d[i], r[i] = d[i]+tmp-eps;
			}
		}
	}

	int cnt = 0, nt = 0;
	rep(i, 0, n-1) {
		if (!ot[i]) continue;
		
		bool flag = false;
		rep(j, 0, m-1) {
			if (l[i] <= p[j] && p[j] <= r[i]) {
				lk[j].push_back(i);
				flag = true;
			}
		}
		if (flag) cnt++;
	}

	sort(po, po+m, [](int x, int y) -> bool {
		return lk[x].size() > lk[y].size();
	});

	rep(i, 0, m-1) {
		bool flag = true;

		for (int j : lk[po[i]]) {
			if (!used[j]) {
				used[j] = 1;
				flag = false;
			}
		}
		if (flag) nt++;
	}

	cout << cnt << " " << nt << endl;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
