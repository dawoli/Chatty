#include <bits/stdc++.h>
using namespace std;
#define int long long
int tot = 0,fa[10020],sz[10020],nd[20];

template <typename T> void read(T &t)
{
	char c = getchar();
	int f = 1;
	t = 0;
	while(c < '0' || c > '9')
	{
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		t = (t << 3) + (t << 1) + (c ^ 48);
		c = getchar();
	}
	t *= f;
}

int find(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

struct Edge{
	int a,b,c;
}e[1100010];

void addEdge(int u,int v,int w)
{
	e[++tot] = (Edge){u,v,w};
}

void merge(int x,int y)
{
	if(x > y)
		swap(x,y);
	fa[y] = x;
	sz[x] += sz[y];
}

bool cmp(Edge yige,Edge erge)
{
	return yige.c < erge.c;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,tmp;
	read(n),read(m),read(k);
	for(int i = 1; i <= m; i++)
	{
		read(u),read(v),read(w);
		addEdge(u,v,w);
	}
	for(int i = 1; i <= k; i++)
	{
		read(nd[i]);
		for(int j = 1; j <= n; j++)
		{
			read(tmp);
			addEdge(i + n,j,tmp);
		}
	}
	sort(e + 1,e + tot + 1,cmp);
	int all = (1 << k) - 1,res = -1;
	for(int st = all; st >= 0; st--)
	{
		int ans = 0;
		for(int i = 1; i <= n + k; i++)
			fa[i] = i,sz[i] = 1;
		int tmpCnt = 0;
		for(int i = 1; i <= k; i++)
		{
			if((st & (1 << (i - 1))) != 0)
				ans += nd[i],tmpCnt++; 
		}
		if(res != -1 && ans > res)
			continue;
		bool flag = true;
		for(int i = 1; i <= tot; i++)
		{
			int x = e[i].a,y = e[i].b,z = e[i].c;
			if(x > n && (st & (1 << (x - n - 1))) == 0)
				continue;
			if(y > n && (st & (1 << (y - n - 1))) == 0)
				continue;
			int cjhfx = find(x),cjhfy = find(y);
			if(cjhfx == cjhfy)
				continue;
			merge(cjhfx,cjhfy);
			ans += z;
			if(res != -1 && ans > res)
			{
				flag = false;
				break;
			}
			if(sz[1] == n + tmpCnt)
				break;
		}
		if(!flag)
			continue;
		if(sz[1] != n + tmpCnt)
			continue;
		if(res == -1 || ans < res)
			res = ans;
	}
	cout << res << '\n';
	return 0;
}
