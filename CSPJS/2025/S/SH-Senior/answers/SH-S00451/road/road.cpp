#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[10005][10005];
long long mon[10005],ans[10005];
void dfs(int x)
{
	for(int i = 2;i <= n;i++)
	{
		if(i != x && mon[i] > a[i][x])
		{
			mon[i] = a[i][x];
			dfs(i);
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(a,0x3f,sizeof(a));
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v] = w;
		a[v][u] = w;
	}
	long long c,f[10005],cnt;
	for(int i = 1;i <= k;i++)
	{
		scanf("%d",&c);
		cnt += c;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&f[i]);
			cnt += f[i];
		}
		for(int j = 1;j <= n;j++)
		{
			for(int k = 1;k <= n;k++)
			{
				a[j][k] = min(a[j][k],f[j] + f[k] + c);
				//cout << f[j] + f[k] + c << " ";
			}
			//cout << endl; 
		}
	}
	if(cnt == 0)
	{
		cout << 0;
		return 0;
	}
	memset(mon,0x3f,sizeof(mon));
	mon[1] = 0;
	dfs(1);
	long long cnt2 = 0;
	for(int i = 1;i <= n;i++)
	{
		cnt2 += mon[i];
	}
	printf("%d",cnt2);
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/
