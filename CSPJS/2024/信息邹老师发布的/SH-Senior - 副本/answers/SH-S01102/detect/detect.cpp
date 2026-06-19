#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 2;
int T;
int n, m, L, V;
int d[N], v[N], a[N];
int p[N];
int mp[N], cx[N];
int cnt, ans;
int maxai1, maxai2;

void init() {
	n = 0;
	m = 0;
	L = 0;
	V = 0;
	maxai1 = 1e9;
	maxai2 = -1e9;
	cnt = 0;
	ans = 0;
	memset(d, 0, sizeof(d));
	memset(v, 0, sizeof(v));
	memset(a, 0, sizeof(a));
	memset(p, 0, sizeof(p));
	memset(mp, 0, sizeof(mp));
	memset(cx, 0, sizeof(cx));
}

int main () {
	freopen ("detect.in", "r", stdin);
	freopen ("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while ( ~ -- T ) {
		init();
		cin >> n >> m >> L >> V;
//		vector<vector<bool>> mp;
		for (int i = 1; i <= n; i ++) {
			cin >> d[i] >> v[i] >> a[i];
			maxai1 = max(a[i], maxai1);
			maxai2 = max(a[i], maxai2);
		}
		for (int i = 1; i <= m; i ++) {
			cin >> p[i];
		}
		vector<int> px[m + 1];
		for (int i = 1; i <= n; i ++) {
			bool flag = 0;
			for (int j = 1; j <= m; j ++) {
				if (p[j] < d[i]) {
					continue;
				}
				double tmpv2 = (v[i] * v[i] + 2 * a[i] * abs(p[j] - d[i])) / 1.0;
				if (tmpv2 <= 0) {
					break;
				}
				double tmp = sqrt(tmpv2);
//				cout << "car " << i << " at " << j << " speed: " << tmp << endl;
				if ( (tmp / 1.0) > V) {
//					cout << "overspeed " << i << " at " << j << " speed: " << tmp << endl;
					flag = 1;
					px[j].push_back(i);
//					mp[i] ^= (1 << j);
//					cout << mp[i] << "!! ";
					cx[i] ++;
				}
			}
			if (flag == 1) {
				cnt ++;
			}
		}
		for (int i = 1; i <= n; i ++) {
			bool flag = 1;
			for (auto j : px[i]) {
				if (cx[j] == 1) {
					flag = 0;
				}
			}
			if (flag) {
				for (auto j : px[i]) {
					cx[j] --;
				}
				ans ++;
			}
		}
		for (int i = 1; i <= n; i ++) {
//			cout << px[i].size() << " ";
			if (px[i].size() == cnt) {
				ans = m - 1;
				break;
			}
		}
//		cout << "\n";
		cout << cnt << " " << ans << "\n"; 
	}
	return 0;
}
