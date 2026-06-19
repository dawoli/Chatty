#include <bits/stdc++.h>
using namespace std;
int T, n, m, L, V, q[1000005], p[100005], l[100005], r[100005], o[100005], vzero[100005], acc[100005], cnt;
struct node {
	int x, y;
} C[100005];
bool cmp(node P, node Q) {
	return P.y < Q.y;
}
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout); 
	cin >> T;
	while(T--) {
		memset(q, 0, sizeof q);
		cnt = 0;
		cin >> n >> m >> L >> V;
		++L;
		for(int i = 1; i <= n; ++i) {
			cin >> o[i] >> vzero[i] >> acc[i];
			++o[i];
			if(acc[i] == 0) {
				if(vzero[i] > V) {
					l[i] = o[i];
					r[i] = L;
				}
				else {
					l[i] = 1;
					r[i] = 0;
				}
			}
			if(acc[i] < 0) {
				if(vzero[i] > V) {
					double rr = o[i] + 1.0 * (vzero[i] * vzero[i] - V * V) / (-2 * acc[i]);
					l[i] = o[i];
					if(rr - 1e-8 >= L + 1) {
						r[i] = L;
					}
					else {
						r[i] = floor(rr - 1e-8);
					}
				}
				else {
					l[i] = 1;
					r[i] = 0;
				}
			}
			if(acc[i] > 0) {
				if(vzero[i] > V) {
					l[i] = o[i];
					r[i] = L;
				}
				else {
					double ll = o[i] + 1.0 * (vzero[i] * vzero[i] - V * V) / (-2 * acc[i]);
					if(ll + 1e-8 > L) {
						l[i] = 1;
						r[i] = 0;
					}
					else {
						l[i] = ceil(ll + 1e-8);
						r[i] = L;
					}
				}
			}
		}
		for(int i = 1; i <= m; ++i) {
			cin >> p[i];
			++p[i];
			q[p[i]]++;
		}
		for(int i = 1; i <= L; ++i) {
			q[i] = q[i - 1] + q[i];
		}
		int ans1 = 0;
		for(int i = 1; i <= n; ++i) {
			if(q[r[i]] > q[l[i] - 1]) {
				++ans1;
				C[++cnt] = {l[i], r[i]};
			}
		}
		sort(C + 1, C + cnt + 1, cmp);
		int ans2 = 0, rig = 0;
		for(int i = 1; i <= cnt; ++i) {
			if(C[i].x <= rig) {
				continue;
			}
			int np = upper_bound(p + 1, p + m + 1, C[i].y) - p - 1;
			rig = p[np];
			++ans2;
		}
		cout << ans1 << " " << m - ans2 << endl; 
	}
	return 0;
} 
// ORZ COMPOSITE_FUNCTION
// ORZ JXY2011
// ORZ LITTLEACBG
// ORZ LIAOYANXU
// ORZ TIANTIAN2021

// everything i want to say is in T4 code
