#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define X first
#define Y second 
const int N = 1e5 + 7;
int T, n, m, l, V, d[N], v[N], a[N], p[N];
vector<pii> vc;
bool cmp(pii A, pii B) {
	return A.Y < B.Y;
}
int read() {
	int x = 0;
	bool f = 0;
	char ch;
	for (ch = getchar(); ch > '9' || ch < '0'; ch = getchar())
		f |= (ch == '-');
	for (; ch <= '9' && ch >= '0'; ch = getchar())
		x = (x << 3) + (x << 1) + (ch ^ 48);
	return (f ? -x : x);
}
signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);	
	T = read();
	while (T--) {
		n = read(), m = read(), l = read(), V = read();
		for (int i = 1; i <= n; ++i) 
			d[i] = read(), v[i] = read(), a[i] = read();
		for (int i = 1; i <= m; ++i)
		 	p[i] = read();
		sort(p + 1, p + m + 1);
		int ct = 0;
		vc.clear();
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 0) {
				int p3 = lower_bound(p + 1, p + m + 1, d[i]) - p;
				if (p3 <= m && v[i] > V) ++ct, vc.push_back(make_pair(p3, m));//, cout << p3 << " A " << n << endl;
				continue;
			}
			double p2 = (1. * V * V - 1. * v[i] * v[i]) / (2 * a[i]);
// 			cout << i << ' ' << p2 << endl;
			 if (a[i] > 0) {
				int pos = lower_bound(p + 1, p + m + 1, d[i]) - p, p3 = upper_bound(p + 1, p + m + 1, d[i] + (int)(p2)) - p;
				if (p3 <= m && pos <= m) ++ct, vc.push_back(make_pair(p3, m));//,		cout << p3 << " B " << n << endl;
				
			} else {
				int pos = lower_bound(p + 1, p + m + 1, d[i]) - p, p3 = lower_bound(p + 1, p + m + 1, d[i] + ceil(p2)) - p - 1;
				if (pos <= p3) ++ct, vc.push_back(make_pair(pos, p3));//,cout << pos << " C " << p3 << endl;
			}
//				cout << i << endl;
		}
		sort(vc.begin(), vc.end(), cmp);
		int ct2 = 0, la = -1;
		for (int i = 0; i < vc.size(); ++i) {
			pii c = vc[i];
			if (c.X <= la) continue;
			++ct2, la = c.Y;
//			cout << c.Y << endl;
		}
		printf("%lld %lld\n", ct, m - ct2);
	}
} 
