#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int floor_div(int a, int b) {
	return a / b;
}
int ceil_div(int a, int b) {
	if (a % b == 0)
		return a / b;
	return a / b + 1;
}

namespace August_Light {
	int n, m, L, V;
	int p[MAXN];
	struct Itv { // Interval
		int l, r;
		Itv(int l = -1, int r = -2) : l(l), r(r) {}
		friend bool operator<(Itv &A, Itv &B) {
			if (A.r == B.r)
				return A.l < B.l;
			return A.r < B.r;
		}
	};
	Itv t[MAXN];
	Itv q[MAXN];
	
	void clear() {
		rep(i, 1, n)
			t[i].l = -1, t[i].r = -2;
	}
	
	void Main() {
		cin >> n >> m >> L >> V;
		rep(i, 1, n) {
			int d, v, a; cin >> d >> v >> a;
			if (a == 0) {
				if (v > V)
					t[i] = Itv(d, L);
			} else if (a > 0) {
				if (v > V) {
					t[i] = Itv(d, L);
				} else {
					int s = floor_div(V * V - v * v, 2 * a) + 1;
					if (d + s <= L)
						t[i] = Itv(d + s, L);
				}
			} else { // if (a < 0)
				if (v > V) {
					int s = ceil_div(v * v - V * V, -2 * a) - 1;
					t[i] = Itv(d, d + s);
				}
			}
			//cerr << "[" << t[i].l << ", " << t[i].r << "]\n";
		}
		rep(i, 1, m)
			cin >> p[i];
		int N = 0;
		rep(i, 1, n) {
			int l = t[i].l, r = t[i].r;
			if (l > r)
				continue;
			int posl = lower_bound(p+1, p+m+1, l) - p;
			int posr = upper_bound(p+1, p+m+1, r) - p - 1;
			//cerr << "[" << posl << " " << posr << "]\n";
			if (posl <= posr)
				q[++N] = Itv(posl, posr);
		}
		cout << N << ' ';
		sort(q+1, q+N+1);
		Itv cur = Itv(-1, -1);
		int ans = 0;
		rep(i, 1, N) {
			int l = q[i].l, r = q[i].r;
			if (l > cur.r) {
				ans++;
				cur = q[i];
			} else
				cur = Itv(l, cur.r);
		}
		cout << m - ans << '\n';
		clear();
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T; cin >> T; while (T--) {
		August_Light::Main();
	}
	return 0;
}
