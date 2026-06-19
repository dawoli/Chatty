#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const double eps = 1e-5;
const int N = 100005;
const int INF = 0x3f3f3f3f;
int n, m;
int ml, lv;
int d[N], v[N], a[N], p[N];
int Acnt, Bcnt, Ccnt;
int maxp;
int nsans = INF;
int ok[30][30]; int flg[30];
double speed(int sv, int av, int s) { return (db)(sqrt(    (db)(sv*sv+2*av*s)     )); }
//bool equa(double a, double b) { if(fabs(a - b) <= eps) return 1; return 0; }
void clear() {
	n = m = ml = lv = Acnt = Bcnt = Ccnt = maxp = 0; nsans = INF;
	memset(d, 0, sizeof(d));
	memset(v, 0, sizeof(v));
	memset(a, 0, sizeof(a));
	memset(p, 0, sizeof(p));
	memset(ok, 0, sizeof(ok));
	memset(flg, 0, sizeof(flg));
}
void dfs(int u, int cnt, int *v, int vcnt) {
	if(u == m + 1) {
//		cout << "hei";		
		int d[30]; memset(d, 0, sizeof(d));
		rep(i, 1, n) {
			rep(j, 1, vcnt) {
				d[i] = (d[i] | ok[i][v[j]]);
			} 
		}
		bool iseq = 1;
//		cout << vcnt << ":";
//		rep(i, 1, vcnt) cout << v[i] << ' '; cout << '\n'; 
//		rep(i, 1, n) cout << d[i] << ' '; cout << '\n';
		rep(i, 1, n) 
			if(d[i] != flg[i]) {
				iseq = 0;
				break;
			}
		if(iseq) {
			nsans = min(nsans, cnt);
//			if(cnt == 3) cout << "heihei" << '\n';
//			cout << cnt << ":\n";
//			rep(ccc, 1, vcnt) cout << v[ccc] << ' '; cout << '\n';
		}
		return;
	}
	dfs(u + 1, cnt, v, vcnt);
	v[vcnt + 1] = u;
	dfs(u + 1, cnt + 1, v, vcnt + 1);
}
void solve() {
	cin >> n >> m >> ml >> lv;
	rep(i, 1, n) cin >> d[i] >> v[i] >> a[i], Acnt += (a[i] == 0), Bcnt += (a[i] > 0), Ccnt += (a[i] < 0);
	rep(i, 1, m) cin >> p[i], maxp = max(maxp, p[i]);
	if(Acnt == n) {
		int ans = 0;
		rep(i, 1, n) if(v[i] > lv && d[i] <= maxp) ++ ans;
		cout << ans << ' ' << (ans == 0 ? m : m - 1) << '\n';
		return;
	} else {
		if(n <= 20) {
//			cout << "hei999";
			int blvans = 0;
			rep(i, 1, n) {
				int fir = -1;
				rep(j, 1, m) if(p[j] >= d[i]) { fir = j; break; }
				if(fir == -1) continue;
				rep(j, fir, m) {
					double spd = speed(v[i], a[i], p[j] - d[i]);
					if(spd > lv) ok[i][j] = 1, flg[i] = 1;
				}
			}
			rep(i, 1, n) if(flg[i] == 1) ++ blvans;
//			rep(i, 1, n) {
//				rep(j, 1, m) {
//					cout << ok[i][j] << ' ';
//				}
//				cout << '\n';
//			}
//			cout << "hei0";
			int s[30]; memset(s, 0, sizeof(s));
//			cout << "hei1";
			dfs(1, 0, s, 0);
//			cout << "hei2";
			cout << blvans << ' ' << m - nsans << '\n';
		} 
		if(n > 20) {
			if(Bcnt == n) {
				int blvans = 0;
				rep(i, 1, n) {
					if(d[i] > maxp) continue;
					double spd = speed(v[i], a[i], p[m] - d[i]);
					if(spd > lv) ++ blvans;
				}
				cout << blvans << ' ' << (blvans == 0 ? m : m - 1) << '\n';
			}
			if(Ccnt == n) {
				// 
			}
		}
	}
}
signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T = 1; cin >> T;
	while(T --) {
		clear();
		solve();
	}
	return 0;
} 
