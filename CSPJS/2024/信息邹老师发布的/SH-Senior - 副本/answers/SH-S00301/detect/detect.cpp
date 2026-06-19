#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[100010],vis[100010],nd[100010],id = 0,chg[100010];

template <typename T> void read(T &t)
{
	int f = 1;
	char c = getchar();
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

struct Car
{
	int d,v,a;
	double ed;
}c[100010];

double calS(int vBeg,int a,double t)
{
	return (double)(vBeg * t) + (double)(0.5 * a * t * t);
}

int calV(int vBeg,int a,int s)
{
	return (long long)(vBeg * vBeg + 2LL * a * s);
}

signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	memset(vis,-1,sizeof(vis));
	int T;
	read(T);
	while(T--)
	{
		memset(chg,0,sizeof(chg));
		id = 0;
		int n,m,L,V,ans1 = 0,ans2 = 0;
		read(n),read(m),read(L),read(V);
		for(int i = 1; i <= n; i++)
		{
			nd[i] = 0;
			read(c[i].d),read(c[i].v),read(c[i].a);
			if(c[i].a >= 0)
				c[i].ed = L + 1;
			else
			{
				double tmp = c[i].v * 1.0 / (-c[i].a);
				c[i].ed = c[i].d + calS(c[i].v,c[i].a,tmp);
			}
		}
		for(int i = 1; i <= m; i++)
			read(p[i]);
		for(int i = 1; i <= n; i++)
		{
			bool flag = true;
			for(int j = 1; j <= m; j++)
			{
				if(c[i].d > p[j])
					continue;
				if(c[i].ed < p[j])
					break;
				if(calV(c[i].v,c[i].a,p[j] - c[i].d) > V * V)
				{
					ans1 += flag;
					flag = false;
					if(vis[j] != T)
					{
						chg[j] = ++id;
						nd[i] |= (1LL << (id - 1));
						vis[j] = T;
					}
					else
						nd[i] |= (1LL << (chg[j] - 1));
				}
			}
		}
		if(ans1 == 0)
		{
			cout << 0 << " " << m << '\n';
			continue;
		}
		for(int i = 0; i < (1LL << id); i++)
		{
			bool ok = true;
			int I = i,now = 0;
			while(I)
			{
				now++;
				I -= (I & -I);
			}
			if(m - now <= ans2)
				continue;
			for(int j = 1; j <= n; j++)
			{
				if(nd[j] && !(i & nd[j]))
				{
					ok = false;
					break;
				}
			}
			if(ok)
				ans2 = m - now;
		}
		cout << ans1 << " " << ans2 << '\n';
	}
	return 0;
}
