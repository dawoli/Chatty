#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
struct node
{
	ll ui,vi,wi;
};
ll to[15][20005];
ll a[20005] = {};
node b1[1020005] = {};
int find(int k)
{
	if (a[k]) return a[k] = find(a[k]);
	return k;
}
bool cmp(node a,node b)
{
	return a.wi < b.wi;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
	{
		scanf("%lld",&b1[i].ui);
		scanf("%lld",&b1[i].vi);
		scanf("%lld",&b1[i].wi);
	}
	for (int i = 1; i <= k; i ++) for (int j = 1;j <= n + 1; j ++)
	{
		scanf("%lld",&to[i][j]);
	}
	ll ans = 1e14;
	ll to1 = pow(2,k) - 1;
	for (int i = 0; i <= to1; i ++)
	{
		memset(a,0,sizeof(a));
		node b[2000005];
		for (int j = 1; j <= m; j ++) b[j] = b1[j];
		ll w = 0;
		ll to2 = i,num = 1;
		ll nt = n,mt = m;
		int flag = 0;
		while (to2 != 0)
		{
			if (to2 % 2)
			{
				nt ++;
				w += to[num][1];
				if (w > ans)
				{
					flag = 1;
					break;
				}
				for (int j = 2; j <= n + 1; j ++)
				{
					node t;
					t.ui = nt;
					t.vi = j - 1;
					t.wi = to[num][j];
					b[++mt] = t;
				}
			}
			num ++;
			to2 /= 2;
		}
		if (flag) continue;
		sort(b + 1,b + mt + 1,cmp);
		nt --;
		ll roa = 1;
		while (nt)
		{
			if (find(b[roa].ui) != find(b[roa].vi))
			{
				a[find(b[roa].vi)] = find(b[roa].ui);
				w += b[roa].wi;
				if (w > ans)
				{
					flag = 1;
					break;
				}
				nt --;
			}
			roa ++;
		}
		if (flag) continue;
		ans = min(ans,w);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
