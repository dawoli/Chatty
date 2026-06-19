#include<bits/stdc++.h>
using namespace std;

struct ti
{
	int d, id;
};

bool operator<(ti a, ti b)
{
	return a.d < b.d;
};

const int N = 100005, A = 200005;
int a[N], b[N], c[N];
ti a1[A], a2[A], a3[A];
bool t[N];

void solve()
{
	memset(t, 0, sizeof(t));
	int n, cnta = 0, cntb = 0, cntc = 0, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] >= b[i] && a[i] >= c[i])
		{
			a1[++cnta] = {a[i] - b[i], i};
			a1[++cnta] = {a[i] - c[i], i};
			ans += a[i];
		}
		else if(b[i] >= c[i])
		{
			a2[++cntb] = {b[i] - a[i], i};
			a2[++cntb] = {b[i] - c[i], i};
			ans += b[i]; 
		}
		else
		{
			a3[++cntc] = {c[i] - b[i], i};
			a3[++cntc] = {c[i] - a[i], i};
			ans += c[i];
		}
	}
	if(cnta <= n && cntb <= n && cntc <= n)
	{
		printf("%d\n", ans);
		return;
	}
	if(cnta > n)
	{
		int dt = (cnta - n) / 2;
		sort(a1 + 1, a1 + cnta + 1);
		for(int i = 1; i <= cnta; ++i)
		{
			if(dt == 0) break;
			int id = a1[i].id, d = a1[i].d;
			if(t[id] == 0)
			{
				ans -= d;
				t[id] = 1;
				--dt;
			}
		}
		printf("%d\n", ans);
	}
	if(cntb > n)
	{
		int dt = (cntb - n) / 2;
		sort(a2 + 1, a2 + cntb + 1);
		for(int i = 1; i <= cntb; ++i)
		{
			if(dt == 0) break;
			int id = a2[i].id, d = a2[i].d;
			if(t[id] == 0)
			{
				ans -= d;
				t[id] = 1;
				--dt;
			}
		}
		printf("%d\n", ans);
	}
	if(cntc > n)
	{
		int dt = (cntc - n) / 2;
		sort(a3 + 1, a3 + cntc + 1);
		for(int i = 1; i <= cntc; ++i)
		{
			if(dt == 0) break;
			int id = a3[i].id, d = a3[i].d;
			if(t[id] == 0)
			{
				ans -= d;
				t[id] = 1;
				--dt;
			}
		}
		printf("%d\n", ans);
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();
}
