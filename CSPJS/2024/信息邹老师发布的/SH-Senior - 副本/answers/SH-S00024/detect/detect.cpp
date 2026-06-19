#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 100005
#define M 100005

int n, m, L, V;
int d[N];
int v[N];
int a[N];
int l[N], r[N];
int p[M];

#define getlrseg(x) int lseg = x * 2, rseg = x * 2 + 1;

#define INF 0x3f3f3f3f3f3f3f3f

struct SegTree {
	struct Segment {
		int l, r;
		int mid;
		int mx;
		int mxp;
		int toAdd;
	} t[M * 4];
	
	int ll, rr, vv;
	int mxvv, mxpp;
	
	void push(int x) {
		getlrseg(x);
		t[lseg].toAdd += t[x].toAdd;
		t[rseg].toAdd += t[x].toAdd;
		t[lseg].mx += t[x].toAdd;
		t[rseg].mx += t[x].toAdd;
		t[x].toAdd = 0;
	}
	
	void pull(int x) {
		getlrseg(x);
		t[x].toAdd = 0;
		if (t[lseg].mx > t[rseg].mx) {
			t[x].mx = t[lseg].mx;
			t[x].mxp = t[lseg].mxp;
		} else {
			t[x].mx = t[rseg].mx;
			t[x].mxp = t[rseg].mxp;
		}
	}
	
	void _build(int x, int l, int r) {
		getlrseg(x);
		t[x].l = l;
		t[x].r = r;
		t[x].mid = (l + r) >> 1;
		t[x].mxp = l;
		t[x].mx = 0;
		t[x].toAdd = 0;
		if (l != r) {
			_build(lseg, l, t[x].mid);
			_build(rseg, t[x].mid + 1, r);
		}
	}
	
	void build() {
		_build(1, 1, m);
	}
	
	void _add(int x) {
		if (t[x].r < ll || t[x].l > rr) {
			return;
		}
		if (t[x].l >= ll && t[x].r <= rr) {
			t[x].mx += vv;
			t[x].toAdd += vv;
		} else {
			getlrseg(x);
			push(x);
			_add(lseg);
			_add(rseg);
			pull(x);
		}
	}
	
	void add(int l, int r, int v) {
		ll = l;
		rr = r;
		vv = v;
		_add(1);
	}
	
	void _mx(int x) {
		if (t[x].r < ll || t[x].l > rr) {
			return;
		}
		if (t[x].l >= ll && t[x].r <= rr) {
			if (t[x].mx > mxvv) {
				mxvv = t[x].mx;
				mxpp = t[x].mxp;
			}
		} else {
			getlrseg(x);
			push(x);
			_mx(lseg);
			_mx(rseg);
		}
	}
	
	int mx(int l, int r) {
		ll = l;
		rr = r;
		mxvv = -INF;
		_mx(1);
		return mxvv;
	}
	
	int mxp() {
		return mxpp;
	}
} segt;

struct Seg {
	int l, r;
	
	bool operator<(const Seg &x) const {
		if (l != x.l) {
			return l < x.l;
		} else {
			return r > x.r;
		}
	}
};
multiset<Seg> s;

signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%lld", &t);
	while (t--) {
		s.clear();
		scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
		bool flagA = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
			if (a[i] < 0) {
				flagA = 0;
			}
		}
		for (int i = 1; i <= m; i++) {
			scanf("%lld", &p[i]);
		}
		sort(p + 1, p + m + 1);
		int cnt = 0;
		if (!flagA) {
			segt.build();
		}
		for (int i = 1; i <= n; i++) {
			l[i] = 0;
			r[i] = 0;
			if (a[i] == 0) {
				if (v[i] > V) {
					l[i] = d[i];
					r[i] = L;
				}
			} else if (a[i] > 0) {
				if (v[i] > V) {
					l[i] = d[i];
					r[i] = L;
				} else {
					double s = (double)(V * V - v[i] * v[i]) / 2 / a[i];
					if ((double)d[i] + s < L) {
						l[i] = (int)(d[i] + s + 1);
						r[i] = L;
					}
				}
			} else if (a[i] < 0) {
				if (v[i] > V) {
					double s = (double)(V * V - v[i] * v[i]) / 2 / a[i];
					if (d[i] + s <= L) {
						l[i] = d[i];
						r[i] = ceil(d[i] + s - 1);
					} else {
						l[i] = d[i];
						r[i] = L;
					}
				}
			}
			if (l[i] || r[i]) {
				int pl = lower_bound(p + 1, p + m + 1, l[i]) - p;
				if (pl != m + 1 && p[pl] <= r[i]) {
					cnt++;
					if (!flagA) {
						int pr = upper_bound(p + 1, p + m + 1, r[i]) - p - 1;
						segt.add(pl, pr, 1);
						s.insert(Seg {pl, pr});
					}
//					cerr << "! " << pl << ' ' << pr << endl;
				}
			}
		} 
//		for (int i = 1; i <= m; i++) {
//			cerr << segt.mx(i, i) << ' ';
//		}
//		cerr << endl;
		printf("%lld ", cnt);
		if (flagA) {
			if (cnt == 0) {
				printf("%lld\n", m);
			} else {
				printf("%lld\n", m - 1);
			}
		} else {
			int ans = 0;
			while (cnt) {
				int mxv = segt.mx(1, m);
				int mxp = segt.mxp();
	//			cerr << "mxv = " << mxv << ", mxp = " << mxp << endl;
				ans++;
				for (auto i = s.begin(); i != s.end() && i->l <= mxp; ) {
					if (i->r >= mxp) {
						segt.add(i->l, i->r, -1);
	//					cerr << "deleting: " << i->l << ' ' << i->r << endl;
						s.erase(i++);
						cnt--;
					} else {
						i = s.lower_bound(Seg {i->l + 1, INF});
					}
				}
			}
			printf("%lld\n", m - ans);
		}
	}
}
