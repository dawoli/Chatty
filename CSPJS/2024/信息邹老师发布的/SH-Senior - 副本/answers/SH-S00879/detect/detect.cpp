#include <bits/stdc++.h>
#define eps 1e-10

using namespace std;

typedef long long ll;

double L[100005], R[100005], P[100005];

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		double S, V;
		cin >> n >> m >> S >> V;
		for (int i = 1; i <= n; i++) {
			double d, v, a;
			ll dll, vll, all;
			cin >> dll >> vll >> all;
			d = dll, v = vll, a = all;
			double l = -1, r = -1;
			if (a == 0) {
				if (v > V) l = d, r = S;
			} else if (a < 0) {
				if (v > V) {
					l = d;
					r = min(S, d + (V + v) * (V - v) / (2 * a) - eps);
				}
			} else {
				if (d + (V + v) * (V - v) / (2 * a) + eps <= S) {
					l = d + (V + v) * (V - v) / (2 * a) + eps;
					r = S;
				}
				if (v > V) {
					l = d;
					r = S;
				}
			}
			L[i] = l, R[i] = r;
		}
		for (int i = 1; i <= m; i++) {
			ll pll;
			cin >> pll;
			P[i] = pll;
		}
		int ans1 = 0;
		set<pair<int, int> > C;
		for (int i = 1; i <= n; i++) {
			int l = lower_bound(P + 1, P + m + 1, L[i]) - P, r = upper_bound(P + 1, P + m + 1, R[i]) - P;
			if (l != r) {
				ans1++;
				C.insert({-l, r - 1});
			}
//			cout << ans << endl;
//			cout << L[i] << " " << R[i] << " "
//				 << *lower_bound(P + 1, P + m + 1, L[i]) << " "
//				 << *lower_bound(P + 1, P + m + 1, R[i]) << " "
//				 << *upper_bound(P + 1, P + m + 1, L[i]) << " "
//				 << *upper_bound(P + 1, P + m + 1, R[i]) << "\n";
		}
		int ans2 = m, x = 1e9;
		for (auto i : C) {
//			cout << -i.first << " " << i.second << " " << ans2 << endl;
			if (i.second < x) {
				x = -i.first;
				ans2--;
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}

