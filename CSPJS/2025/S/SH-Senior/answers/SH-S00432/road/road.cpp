#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
typedef long long ll;
int n , m , k , a[15][10005] , c[15] , f[10005];
ll minn = 1e18;
bool vis[15];
struct edge
{
	int u , v , w;
	bool operator < (const edge &y) const
	{
		return w < y.w;
	}
} e[2000005];
int search(int id)
{
	return (f[id] == id) ? id : f[id] = search(f[id]);
}
void dfs(int id , int num , ll sum)
{
	iota(f + 1 , f + num + 1 , 1);
	if (id == k + 1)
	{
		int cnt = 0;
		ll ans = sum;
		for (int i = 1; i <= m && cnt < num - 1; i++)
		{
			if (e[i].u > n && !vis[e[i].u - n]) continue;
			int x = search(e[i].u) , y = search(e[i].v);
			if (x == y) continue;
			f[x] = y;
			cnt ++;
			ans += e[i].w;
		}
		minn = min(minn , ans);
		return;
	}
	vis[id] = false;
	dfs(id + 1 , num , sum);
	vis[id] = true;
	dfs(id + 1 , num + 1 , sum + c[id]);
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &k);
	for (int i = 1; i <= m; i++)
	{
		int u , v , w; scanf("%d%d%d" , &u , &v , &w);
		e[i] = {u , v , w};
	}
	bool flag = true;
	for (int i = 1; i <= k; i++)
	{
		scanf("%d" , &c[i]);
		int p = 0;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d" , &a[i][j]);
			if (!a[i][j]) p = j;
		}
		if (!p || c[i]) flag = false;
	}
	if (flag)
	{
		for (int i = 1; i <= k; i++)
		{
			int p = 0;
			for (int j = 1; j <= n; j++)
				if (!a[i][j]) p = j;
			for (int j = 1; j <= n; j++)
				if (j != p) e[++ m] = {p , j , a[i][j]};
		}
		sort(e + 1 , e + m + 1);
		iota(f + 1 , f + n + 1 , 1);
		ll ans = 0;
		int cnt = 0;
		for (int i = 1; i <= m && cnt < n - 1; i++)
		{
			int x = search(e[i].u) , y = search(e[i].v);
			if (x == y) continue;
			f[x] = y;
			cnt ++;
			ans += e[i].w;
		}
		printf("%lld" , ans);
	}
	else
	{
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				e[++ m] = {n + i , j , a[i][j]};
		sort(e + 1 , e + m + 1);
		dfs(1 , n , 0);
		printf("%lld" , minn);
	}
	return 0;
}
