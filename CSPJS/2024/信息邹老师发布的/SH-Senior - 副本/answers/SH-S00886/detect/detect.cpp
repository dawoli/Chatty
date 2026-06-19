#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
using namespace std;

typedef long double db;
typedef pair<int, int> PII;
void file_IO(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
}

const int N = 1e5 + 10;
int T, n, m, L, V, d[N], a[N], v[N], pos[N];
int cnt = 0, tot = 0;
PII line[N];

bool cmp(PII x, PII y){
	return x.SE < y.SE;
}

int calc(int x, int y, int v0, int aa){
	return v0 * v0 + 2 * aa * (y - x);
}

void solve(){
	cin >> n >> m >> L >> V;
	for (int i = 1; i <= n; i++)
		cin >> d[i] >> v[i] >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> pos[i];
	cnt = tot = 0;
	for (int i = 1; i <= n; i++){
		int p = lower_bound(pos + 1, pos + m + 1, d[i]) - pos;
		if (p > m)	continue;
		if (a[i] == 0){
			if (v[i] > V)
				line[++cnt] = MP(p, m);
		}else if (a[i] > 0){
			int l = p, r = m, res = m + 1;
			while (l <= r){
				int md = (l + r) >> 1;
				if (calc(d[i], pos[md], v[i], a[i]) > V * V)
					res = md, r = md - 1;
				else	l = md + 1;
			}
			if (res <= m)
				line[++cnt] = MP(res, m);
		}else{
			int l = p, r = m, res = m + 1;
			while (l <= r){
				int md = (l + r) >> 1;
				if (calc(d[i], pos[md], v[i], a[i]) <= V * V)
					res = md, r = md - 1;
				else	l = md + 1;
			}
			if (p <= res - 1)
				line[++cnt] = MP(p, res - 1);
		}
	}
	cout << cnt << " " ;
	sort(line + 1, line + cnt + 1, cmp);
	int lstpos = -1;
	for (int i = 1; i <= cnt; i++)
		if (lstpos < line[i].FI)
			++tot, lstpos = line[i].SE;
	cout << m - tot << endl;
}

signed main(){
	file_IO();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T --> 0)
		solve();
	return 0;
}
//liyelin AK IOI
