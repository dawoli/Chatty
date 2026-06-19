#include<bits/stdc++.h>
using namespace std;

struct node
{
	int s,t;
}g[100010];

int d[100010];
int v[100010];
int a[100010];
int p[100010];

bool cmp(node x,node y)
{
	if(x.t != y.t)return x.t < y.t;
	return x.s < y.s; 
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,l,V;
		cin >> n >> m >> l >> V;
		for(int i = 1;i <= n;i++)
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i = 1;i <= m;i++)
			scanf("%d",&p[i]);
		int ans1 = 0,ans2 = m;
		for(int i = 1;i <= n;i++)
		{
			int d1,d2;
			bool flag = 0;
			if(a[i] > 0)
			{
				if(v[i] > V)d1 = d[i],d2 = l,flag = 1;
				else
				{
					d1 = d[i] + (V * V - v[i] * v[i]) / 2 / a[i] + 1;
					if(d1 <= l)flag = 1,d2 = l;
				}
			}
			else if(a[i] < 0)
			{
				if(v[i] > V)d1 = d[i],d2 = d[i] + (V * V - v[i] * v[i]) / 2 / a[i],flag = 1;
			}
			else
			{
				if(v[i] > V)d1 = d[i],d2 = l,flag = 1;
			}
			if(flag)
			{
				int p1,p2;
				p1 = lower_bound(p + 1,p + m + 1,d1) - p;
				p2 = upper_bound(p + 1,p + m + 1,d2) - p - 1;
				if(p[p1] <= d2 && p1 <= m)
				{
					ans1++;
					g[ans1].s = p1;
					g[ans1].t = p2;
				}
			}
		}
		sort(g + 1,g + ans1 + 1,cmp);
		int last = -1;
		for(int i = 1;i <= ans1;i++)
			if(g[i].s > last)
			{
				last = g[i].t;
				ans2--;
			}
		cout << ans1 << " " << ans2 << endl;
	}
    return 0;
}
