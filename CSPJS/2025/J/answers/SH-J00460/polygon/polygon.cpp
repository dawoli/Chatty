#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll n , maxn , tot , cnt , sum;
ll a[N] , vis[N] , v1[N] , v2[N] , v3[N];
void dfs(int u)
{
	if (u == n + 1)
	{
		maxn = 0;
		tot = 0;
		cnt = 0;
		for (int i = 1 ; i <= n ; i ++)
		{
			if (vis[i] == 1)
			{
				maxn = max(maxn , a[i]);
				cnt ++;
				tot += a[i];
			}
		}
		if (v1[tot] == 1 && v2[cnt] == 1 && v3[maxn] == 1)
		{
			return;
		}
		v1[tot] = 1;
		v2[cnt] = 1;
		v3[maxn] = 1;
		if (maxn * 2 < tot && cnt >= 3)
		{
			sum ++;
		}
		return;
	}
	vis[u] = 1;
	dfs(u + 1);
	vis[u] = 0;
	dfs(u + 1);
}
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
	}
	for (int i = 1 ; i <= n ; i ++)
	{
		maxn = 0;
		tot = 0;
		cnt = 0;
		memset(vis , 0 , sizeof(vis));
		dfs(0);
	}
	cout << sum;
	return 0;
}
