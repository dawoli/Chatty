#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long a,b,c;
}e[2000010];

int fa[15010];

bool cmp(node x,node y)
{
	return x.c < y.c;
}

int find(int u)
{
	if(fa[u] == u)return u;
	return fa[u] = find(fa[u]);
}

void merge(int u,int v)
{
	fa[find(u)] = find(v);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long ans = 0;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
	int cnt = m;
	for(int i = 1;i <= k;i++)
	{
		int w;
		cin >> w;
		ans += w;
		for(int j = 1;j <= n;j++)
		{
			scanf("%d",&e[++cnt].c);
			e[cnt].a = n + i,e[cnt].b = j;
		}
	}
	sort(e + 1,e + cnt + 1,cmp);
	for(int i = 1;i <= n + k;i++)fa[i] = i;
	for(int i = 1;i <= cnt;i++)
	{
		int a = e[i].a,b = e[i].b,c = e[i].c;
		if(find(a) != find(b))
		{
			merge(a,b);
			ans += c;
		}
	}
	cout << ans;
	return 0;
}
