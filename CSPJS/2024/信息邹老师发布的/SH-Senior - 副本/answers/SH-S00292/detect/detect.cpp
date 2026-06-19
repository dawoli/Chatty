#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100009;

struct node
{
	int d, a, v;
}x[N];

int n, m, d[N], v[N], a[N], p[N];
bool vst[N];
int tp = 0, lp[N], rp[N];
int pos[N];//the first position beyond V
int pos2[N];
int l, V;
//check = true:chaosu

bool check(int x)
{
	if (a[x] >= 0)
	{
		int l = 1, r = m;
		while(l < r)
		{
			int mid = l + r >> 1; //cout << l << " " << r << "   " << x << " " << p[mid] << endl;
			if (p[mid] < d[x] || v[x]*v[x]+2*a[x]*(p[mid]-d[x]) <= V*V) l = mid + 1;
			else r = mid;
		}
		while (v[x]*v[x]+2*a[x]*(p[l]-d[x]) <= V*V && l <= m) l ++;
		//cout << l << endl;
		if (l > m) return false;//p>d
		lp[tp]=l; rp[tp] = m;
		return true;
	}
	int l = 1, r = m;
	while(l < r)
	{
		int mid = l + r >> 1;
		if (d[x] > p[mid]) l = mid + 1;
		else r = mid;
	}
	while (d[x] > p[l] && l <= m) l ++;
	if (l > m || v[x]*v[x]+2*a[x]*(p[l]-d[x]) > V*V) return false;
	lp[tp]=l;
	while(l < r)
	{
		int mid = l + r >> 1;
		if (v[x]*v[x]+2*a[x]*(p[mid]-d[x]) > V*V) l = mid + 1;
		else r = mid;
	}
	while (v[x]*v[x]+2*a[x]*(p[l]-d[x]) > V*V && l <= m) l ++;
	rp[tp]=l;
	return true;
}

void solve()
{
	tp = 0;
	cin >> n >> m >> l >> V ;
	for (int i = 1; i <= n; ++ i) cin >> d[i] >> v[i] >> a[i];
	for (int i = 1; i <= m; ++ i) cin >> p[i], v[i] = false;
	
	int ans1 = 0, ans2 = 0;
	
	for (int i = 1; i <= n; ++ i)
	{
		tp ++;
		if (!check(i)) {tp --; continue;}
		ans1 ++;
		x[tp] = (node) {d[i], a[i], v[i]};
		//cout << i << "   " << lp[tp] << " " << rp[tp] << endl;
	}
	cout << ans1 << " " << ans1 << endl;
	for (int i = 1; i <= tp; ++ i)
		vst[pos[i]] = true;
}


signed main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t; cin >> t;
	while(t --) solve();

	return 0;
}

