#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100009;

struct turn
{
	int lst = 0;//
	bool f;
}x[N];

int n, m, s[N], a[N], l[N];
int c[N], f[N];
int p[N];

void solve()
{
	cin >> n;
	for (int i = 1; i < N - 2; ++ i) c[i] = l[i] = p[i] = 0;
	for (int i = 1; i <= n; ++ i)
	{
		f[i] = 0;
		cin >> a[i]; s[i] = s[i - 1];
		if (c[a[i]] > 0) l[i] = c[a[i]];
		if (l[i] == i - 1 && i != 1) s[i] += a[i];
		c[a[i]] = i;
		//cout << s[i] << " ";
	}
	//cout << endl;
	
	for (int i = 1; i <= n; ++ i)
	{
		if (!l[i]) continue;
		int len = max(0LL, s[i-1]-s[l[i]+1]);
		if (l[i] && f[l[i]] + len + a[i] > f[i])
			f[i] = f[l[i]] + len + a[i];
	//	cout << f[i] << " ";
		int e = 0, tmp = 0;
		for (int j = 1; j < l[i] - 1; ++ j)
		{
			if (!l[j]) continue;
			tmp = f[j] + max(s[l[i] - 1] - s[j + 1], 0LL);
			if (l[j] != j - 1 && a[j - 1] == a[j + 1]) tmp += a[j + 1];
			e = max(tmp, e); 
		}
		if (l[i] != i - 1 && a[l[i] - 1] == a[l[i] + 1]) e += a[l[i] + 1];
	//	cout << e << " ";
		tmp = 0;
		int u = l[i];
		while(1 && u > 1) {
	//		cout << "1u:" << u << " " << l[u] << " " << l[u - 1] << endl;
			while (l[u] == u - 1 && l[u] > 0) {tmp += a[u]; u = l[u];}
			while (l[u - 1] == u - 2 && l[u-1] > 0) {tmp += a[u - 1]; u = l[u - 1];}
			if (l[u] == 0 && l[u - 1]==0) break;
			if (l[u] != u - 1 && l[u - 1] != u - 2)
			{
				tmp = f[u - 1];
				if (a[u - 2] == a[l[i] + 1] && i - 1 != l[i]) tmp += a[u - 2];
				break;
			}
		}
	//	cout << tmp << " ";
		e = max(tmp, e); tmp = 0;
		u = l[i] - 1;
	//	if (i == 7) cout << " seven " << u << " " << l[u] << endl;
		while(1 && u > 1) {
			while (l[u] == u - 1 && l[u] > 0) { tmp += a[u]; u = l[u]; }
			while (l[u - 1] == u - 2 && l[u-1] > 0) {tmp += a[u - 1]; u = l[u - 1];}
			if (l[u] == 0 && l[u - 1]==0) break;
	//		cout << "00 "<<u << endl;
			if (l[u] < u - 1 && l[u - 1] < u - 2)
			{
	//			cout << "00 "<<i << endl;
				tmp = f[u - 1];
				if (a[u - 2] == a[l[i] + 1] && i - 1 != l[i]) tmp += a[u - 2];
				break;
			}
		}
	//	cout << tmp << " ";
		e = max(tmp, e); tmp = 0;
		f[i] = max(e + len + a[i], f[i]);
	//	cout << e + len + a[i] << " ";
		if(a[l[i] + 1] == a[l[i] - 1]) tmp += a[l[i] - 1];
		f[i] = max(s[l[i] - 1] + tmp + a[i] + len, f[i]);
	//	cout << " " << s[l[i] - 1] + tmp + a[i] + len << endl;
	//	cout << i << "  " << f[i] << endl;
	}
	int ans = 0;
	for (int i = 1, len; i <= n; ++ i)
	{
		ans = max(ans, f[i]);
		if (i < n) len = s[n] - s[i + 1];
		int u = l[i], tmp = 0;
		while(1 && u > 1) {
			while (l[u] == u - 1 && l[u] > 0) {u = l[u];}
			while (l[u - 1] == u - 2 && l[u-1] > 0) {u = l[u - 1];}
			if (l[u] == 0 && l[u - 1]==0) break;
			if (l[u] != u - 1 && l[u - 1] != u - 2)
			{
				if (a[u - 1] == a[i + 1] && i - 1 != l[i]) tmp = a[i + 1];
				break;
			}
		}
		ans = max(ans, f[i] + tmp + len);
		//cout << i << " " << f[i] << " " << tmp << " " << len << endl;
	}
		
	cout << ans << endl;
}

signed main()
{
	freopen("color2.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;cin >> T;
	while(T --) solve();
	return 0;
}

//		f[i][1] = f[i - 1][1]; x0[i] = (node) {i - 1, 1};
//		if (f[l[i]][1] + len + a[i]) > f[i][1])
//			f[i][1] = f[l[i]][1] + len + a[i], x0[i] = (node) {l[i], 1};
//		if (f[i - 1][0] > f[i][1])
//			f[i][1] = f[i - 1][0], x0[i] = (node) {i - 1, 0};
//		
//		f[i][0] = f[i - 1][1]; x1[i] = (node) {i - 1, 1};
//		if (f[l[i]][0] + len + a[i]) > f[i][0])
//			f[i][0] = f[l[i]][1] + len + a[i], x1[i] = (node) {l[i], 1};
//		if (f[i - 1][0] > f[i][0])
//			f[i][0] = f[i - 1][0], x1[i] = (node) {i - 1, 0};
		
//		f[i][1] = max(f[i - 1][1], f[l[i]][1] + max(0, s[i-1]-s[l[i]+1]) + a[i]);
//		f[i][1] = max(f[i - 1][0], f[i][1]);
//		f[i][0] = max(f[i - 1][1], f[l[i]][0] + max(0, s[i-1]-s[l[i]+1]) + a[i]);
//		f[i][0] = max(f[i - 1][0], f[i][0]);

