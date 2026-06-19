#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-5;

const int N = 1e5 + 1;

int d[N], v[N], p[N], a[N], near[N], ava[N];

int n, m, L, V;

void check_near(int x) {
	int nxt = lower_bound(p + 1, p + m + 1, d[x]) - p;
	if(nxt == m + 1) {
		near[x] = m + 1;
		return;
	}
	if(a[x] >= 0) {
		int l = nxt - 1, r = m + 1;
		while(r > l + 1) {
			int mid = (l + r) >> 1;
			int dis = p[mid] - d[x];
			double vt = sqrt(v[x] * v[x] + 2 * a[x] * dis);
			if(vt - eps > V) r = mid;
			else l = mid;
		}
		near[x] = r;
	}
	else {
		int l = nxt - 1, r = m + 1;
		while(r > l + 1) {
			bool flag = true;
			int mid = (l + r) >> 1;
			int dis = p[mid] - d[x];
			double t= - 1.0 * v[x] / a[x];
			if(v[x] * t + 0.5 * a[x] * t * t < dis) flag = false;
			double vt = sqrt(v[x] * v[x] + 2 * a[x] * dis);
			if(flag && vt - eps > V) l = mid;
			else r = mid;
		}
		if(l == nxt - 1) near[x] = -1;
		else near[x] = l;
	}
}

bool check(int pos, int b, int n) {
	int now = p[pos];
	int use = 0;
	for(int i = n; i >= 1; --i) {
		if(a[i] < 0 && near[i] != -1) {
			if(now > p[near[i]]) {
				now = p[lower_bound(p + 1, p + m + 1, d[i]) - p];
				++use;
			}
		}
	}
	return use == b;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
    	cin >> n >> m >> L >> V;
    	for(int i = 1; i <= n; ++i) cin >> d[i] >> v[i] >> a[i];
    	for(int i = 1; i <= m; ++i) cin >> p[i];
    	int ans = 0;
    	for(int i = 1; i <= n; ++i) check_near(i);
    	for(int i = 1; i <= n; ++i) if(near[i] != m + 1 && near[i] != -1) ++ans;
    	cout << ans << " ";
    	int pos = 0 , q = 0, dis = 0, pp = 0;
    	for(int i = 1; i <= n; ++i) if(a[i] >= 0 && near[i] != m + 1) dis = max(dis, p[near[i]]); 
		for(int i = n; i >= 1; --i) {
			if(a[i] < 0 && near[i] != -1) {
				pos = p[lower_bound(p + 1, p + m + 1, d[i]) - p], q = i, pp = lower_bound(p + 1, p + m + 1, d[i]) - p;
				break;
			}
		}
		int now = pos;
		int use = 1;
		for(int i = q - 1; i >= 1; --i) {
			if(a[i] < 0 && near[i] != -1){
				if(now > p[near[i]]) {
					++use;
					now = p[lower_bound(p + 1, p + m + 1, d[i]) - p];
				}
			}
		}
		int bestans = use;
		if(q == 0) {
			cout << m - 1 << '\n';
			continue;
		}
		if(pos >= dis) {
			cout << m - use << '\n';
			continue;
		}
		
		if(dis == 0) {
			cout << m - use;
			continue;
		} 
		int l = pp, r = m + 1;
		while(r > l + 1) {
			int mid = (l + r) >> 1;
			if(check(mid, bestans, n)) l = mid;
			else r = mid;
		}
		if(l < dis) cout << m - bestans - 1;
		else cout << m - bestans;
		cout << '\n';
	}
	return 0;
}
