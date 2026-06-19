#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int T, n, m, L, V, d[N], v[N], a[N], p[N];
bool tag[N], caught[N]; 
namespace c12 { 
	int subtask() {
		for (int i = 1; i <= n; i++)
			caught[i] = false;
		for (int j = 1; j <= m; j++) {
			if (!tag[j]) continue;
			for (int i = 1; i <= n; i++) {
				if (caught[i]) continue; 
				if (p[j] < d[i]) continue;
				if (p[j] == d[i]) {
					if (v[i] > V) {
						caught[i] = true;
						continue;
					}
					continue;
				}
				if (a[i] < 0) {
					if (1ll*v[i]*v[i] < -2ll*a[i]*(p[j]-d[i])) continue;
					if (1ll*v[i]*v[i] + 2ll*a[i]*(p[j]-d[i]) > 1ll*V*V) {
						caught[i] = true;
						continue;
					}
				} else if (a[i] == 0) {
					if (v[i] > V) {
						caught[i] = true;
						continue;
					}
				} else {
					if (1ll*v[i]*v[i] + 2ll*a[i]*(p[j]-d[i]) > 1ll*V*V) {
						caught[i] = true;
						continue;
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += caught[i];
		return cnt;
	}
	void solve() {
		for (int j = 1; j <= m; j++)
			tag[j] = true; 
		int piv = subtask();
		int ans = 0; 
		for (long long i = 0; i < (1ll<<m)-1; i++) {
			int cntb = 0;
			for (int j = 0; j < m; j++)
				tag[j+1] = !!((i>>j)&1), cntb += !!((i>>j)&1);
			if (subtask() == piv)
				ans = max(ans, m-cntb); 
		}
		printf("%d %d\n", piv, ans);
	}
}
bool allZero() {
	for (int i = 1; i <= n; i++)
		if (a[i]) return false;
	return true;
}
bool allOne() {
	for (int i = 1; i <= n; i++)
		if (a[i] <= 0) return false;
	return true;
}
bool allNeg() {
	for (int i = 1; i <= n; i++)
		if (a[i] >= 0) return false;
	return true;
}
//namespace s3A {
//	bool check() {
//		if (n > 3000 || m > 3000) return false;
//		return true;
//	} 
//	void solve() {
//		for (int j = 1; j <= m; j++) {
//			for (int i = 1; i <= n; i++) {
//				if (caught[i]) continue;
//				if (p[j] < d[i]) continue;
//				if (v[i] > V) {
//					caught[i] = true;
//					continue;
//				}
//			}
//		}
//		int cnt = 0;
//		for (int i = 1; i <= n; i++)
//			cnt += caught[i];
//		printf("%d %d\n", cnt, cnt==0?m:(m-1));
//	}
//}
namespace s3B {
	void solve() {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (v[i] <= V) continue;
			if (p[m] >= d[i]) ++cnt;
		}
		printf("%d %d\n", cnt, cnt==0?m:(m-1));
	}
}
//namespace s5A {
//	bool check() {
//		if (n > 3000 || m > 3000) return false;
//		return true;
//	} 
//	void solve() {
//		for (int j = 1; j <= m; j++) {
//			for (int i = 1; i <= n; i++) {
//				if (caught[i]) continue; 
//				if (p[j] < d[i]) continue;
//				if (p[j] == d[i]) {
//					if (v[i] > V) {
//						caught[i] = true;
//						continue;
//					}
//					continue;
//				}
//				if (1ll*v[i]*v[i] + 2ll*a[i]*(p[j]-d[i]) > 1ll*V*V) {
//					caught[i] = true;
//					continue;
//				}
//			}
//		}
//		int cnt = 0;
//		for (int i = 1; i <= n; i++)
//			cnt += caught[i];
//		printf("%d %d\n", cnt, cnt==0?m:(m-1));
//	}
//}
namespace s5B {
	void solve() {
		int cnt = 0;
		long long sqV = 1ll*V*V;
		for (int i = 1; i <= n; i++)
			if (p[m] >= d[i])
				if (1ll*v[i]*v[i] + 2ll*a[i]*(p[m]-d[i]) > sqV)
				++cnt;
		printf("%d %d\n", cnt, cnt==0?m:(m-1));
	}
}
namespace s7A {
	int tr[N+1];
	void add (int i, int x) {
		for ( ; i <= m+1; i += i & -i)
			tr[i] += x;
	}
	int query (int i) {
		int res = 0;
		for ( ; i; i -= i & -i)
			res += tr[i];
		return res;
	}
	void solve() {
		int mnv = numeric_limits<int>::max(), cnt = 0;
		vector<pair<int, int> > itvs;
		vector<bool> tgis;
		for (int i = 1; i <= m+1; i++)
			tr[i] = 0;
		for (int i = 1; i <= n; i++)
			if (v[i] >= V) {
				int x = d[i] + floor(-(1ll*(v[i]-V)*(v[i]-V))*1.0/(2ll*a[i]));
				size_t ub = upper_bound(p+1, p+m+1, x) - p;
				if (ub == m+1) continue;
				--ub;
				size_t lb2 = lower_bound(p+1, p+m+1, d[i]) - p;
				if (lb2 == m+1) continue;
				if (ub > lb2) continue;
				cnt++;
				add(ub, 1);
				add(lb2+1, -1);
				itvs.push_back(make_pair(ub, lb2));
				tgis.push_back(true);
			}
		int fans = 0, cnttk = 0;
		for (;;) {
			int lp = -1, mx = 0;
			for (int i = 1; i <= m; i++) {
				int rv = query(i) - query(i-1);
				if (rv > mx) {
					mx = rv;
					lp = rv;
				}
			}
			if (lp == -1) break;
			fans++;
			for (int i = 0; i < itvs.size(); i++) {
				if (!tgis[i]) continue;
				if (itvs[i].first <= lp && lp <= itvs[i].second) {
					tgis[i] = false;
					++cnttk;
					add(itvs[i].first, -1);
					add(itvs[i].second+1, 1);
				}
			}
			if (cnttk == itvs.size())
				break;
		}
		printf("%d %d\n", cnt, m-fans);
	}
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &d[i], &v[i], &a[i]);
		for (int i = 1; i <= m; i++)
			scanf("%d", &p[i]);
		sort(p+1, p+m+1);
		if (n <= 20 && m <= 20) c12::solve();
		else if (allZero()) s3B::solve();
		else if (allOne()) s5B::solve();
		else if (allNeg()) s7A::solve();
	}
	return 0;
}
