#include <bits/stdc++.h>
#define ULL unsigned long long
#define int long long
using namespace std;
const int P = 1e9 + 7,N = 2e5 + 5,M = 5e6 + 5;
int n,q;
ULL p[M],s[M],t[M];
struct Node{int len; ULL s,t;}a[N];
ULL Hashs(int l,int r)
{
	return s[r] - s[l - 1] * p[r - l + 1];
}
ULL Hasht(int l,int r)
{
	return t[r] - t[l - 1] * p[r - l + 1];
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i < M; i++) p[i] = p[i - 1] * P;
	for (int i = 1; i <= n; i++)
	{
		string x,y;
		cin >> x >> y;
		a[i].len = x.size();
		for (int j = 0; j < a[i].len; j++) a[i].s = a[i].s * P + x[j] - 'a',a[i].t = a[i].t * P + y[j] - 'a';
	}
	while (q--)
	{
		string x,y;
		int ans = 0;
		cin >> x >> y;
		if (x.size() != y.size())
		{
			puts("0");
			continue;
		}
		int l = 0,r = x.size() - 1;
		while (x[l] == y[l]) l++;
		while (x[r] == y[r]) r--;
		l++; r++;
//		cout << l << " " << r << endl;
		for (int i = 0; i < x.size(); i++) s[i + 1] = s[i] * P + x[i] - 'a',t[i + 1] = t[i] * P + y[i] - 'a';
//		cout << Hashs(3,4) << " " << s[4] << " " << s[2] << endl;
		for (int i = 1; i <= n; i++)
		{
			if (a[i].len > x.size()) continue;
			int zl = a[i].len,ll = r - zl + 1,rr = r;
			if (ll <= 0) ll = 1,rr = zl;
//			cout << ll << " " << rr << " " << zl << endl;
			while (ll <= l && rr <= x.size()) ans += (Hashs(ll,rr) == a[i].s && Hasht(ll,rr) == a[i].t),ll++,rr++;
		}
		cout << ans << endl;
	}
	return 0;
}
