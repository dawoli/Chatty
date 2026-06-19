#include<bits/stdc++.h>
// #define int long long
using namespace std;

const int eps = 1e-7;

int n, m, L, V;
struct car {
	int d, v, a;
} c[100005];
struct qj {
	int l, r;
} q[100005];
int p[100005];
int cnt, qcnt;
int tp, ans;

bool cmp(qj A, qj B) {
	if(A.r != B.r)
		return A.r < B.r;
	return A.l > B.l;
}

int ub(int x) {
	int ret = upper_bound(p + 1, p + m + 1, x) - p;
	if(x == p[ret] - 1) return ret - 1;
	else return ret;
} 

void Main() {
	qcnt = cnt = 0;
	tp = 1;
	memset(p, 0, sizeof p);
	for(int i = 0; i <= 100005; i++)
		q[i].l = q[i].r = 0;
	cin >> n >> m >> L >> V;
	ans = m;
	for(int i = 1; i <= n; i++) 
		scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
	for(int i = 1; i <= m; i++)
		scanf("%d", &p[i]);
	for(int i = 1; i <= n; i++) {
		int d = c[i].d, v = c[i].v, a = c[i].a;
		if(p[m] + 1 <= d) continue;
		if(a == 0) {
			if(v > V) {
				cnt++;
				qcnt++;
				q[qcnt].l = ub(d);
				q[qcnt].r = m;
			}
		}
		if(a < 0) {
			int k = lower_bound(p, p + m + 1, d) - p;
			double vv = sqrt(v * v + 2 * a * (p[k] - d));
			if(!(vv > 0)) continue;
			if(vv - V > eps) {
				int ss = ceil(d + (V * V - v * v) / 2.0 / a);
				cnt++;
				qcnt++;
				q[qcnt].r = lower_bound(p + 1, p + m + 1, ss) - p - 1;
				q[qcnt].l = k;
			}
		}
		if(a > 0) {
			double vv = sqrt(v * v + 2 * a * (p[m] - d));
			if(vv - V > eps) {
				qcnt++;
				cnt++;
				int ss = floor(d + (V * V - v * v) / 2.0 / a);
				if(v > V) q[qcnt].l = ub(d);
				else q[qcnt].l = ub(ss);
				q[qcnt].r = m;
			}
		}
	}
	for(int i = 1; i <= cnt; i++) {
		// cout << q[i].l << " " << q[i].r << endl;
	}
	sort(q + 1, q + cnt + 1, cmp);
	cout << cnt << " ";
	for(int i = 1; i <= L; i++) {
		if(i == p[q[tp].r]) {
			ans--;
			while(p[q[tp].l] <= i && i <= p[q[tp].r]) tp++;
		}
		// cout << i << " " << ans << " " << tp << endl;
	}
	cout << ans << '\n';
	// cout << endl;
	return ;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
		Main();
	return 0;
} 
