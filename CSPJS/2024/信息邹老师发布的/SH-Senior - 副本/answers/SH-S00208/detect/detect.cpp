#include <bits/stdc++.h>
using namespace std;
const int N=100002;
const double Eps=1e-11;
struct node
{
	int id;
	double lp,rp;
	bool vis;
} d[N];
int c[N],t,n,m,nc,pre,ans1,ans2;
double p[N],l,v;
bool f[N];
bool cmpl(node d1,node d2)
{
	if (d1.lp!=d2.lp) return d1.lp<d2.lp;
	else return d1.rp<d2.rp;
}
bool cmpr(node d1,node d2)
{
	if (d1.rp!=d2.rp) return d1.rp<d2.rp;
	else return d1.lp<d2.lp;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%lf%lf",&n,&m,&l,&v);
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;++i)
		{
			double dis,vel,acc;
			scanf("%lf%lf%lf",&dis,&vel,&acc);
			d[i].id = i;
			if (acc>Eps)
			{
				double rmt=(v*v-vel*vel)/(acc*2);
				if (vel>v)
				{
					d[i].vis = 1;
					d[i].lp = dis;
					d[i].rp = l;
				}
				else
				{
					if (dis+rmt>=l) d[i].vis = 0;
					else
					{
						d[i].vis = 1;
						d[i].lp = dis+rmt+Eps;
						d[i].rp = l;
					}
				}
			}
			else if (acc<Eps)
			{
				double rmt=(v*v-vel*vel)/(acc*2);
				if (vel>v)
				{
					if (dis+rmt>l)
					{
						d[i].vis = 1;
						d[i].lp = dis;
						d[i].rp = l;
					}
					else
					{
						d[i].vis = 1;
						d[i].lp = dis;
						d[i].rp = dis+rmt-Eps;
					}
				}
				else d[i].vis = 0;
			}
			else
			{
				if (vel>v)
				{
					d[i].vis = 1;
					d[i].lp = dis;
					d[i].rp = l;
				}
				else d[i].vis = 0;
			}
		}
		for (int i=1;i<=m;++i)
			scanf("%lf",&p[i]);
		sort(d+1,d+1+n,cmpl);
		c[0] = 0;
		for (int i=1;i<=n;++i)
		{
			if (!d[i].vis) c[i] = c[i-1]+1;
			else c[i] = c[i-1];
		}
		nc = n-c[n];
		for (int i=1;i<=nc;++i)
			d[i] = d[i+c[i]];
		for (int i=1,j=1;i<=m;++i)
		{
			while (j<=nc && d[j].lp<=p[i])
			{
				if (d[j].rp>=p[i]) f[d[j].id] = 1; 
				++j;
			}
		}
		ans1 = 0;
		for (int i=1;i<=n;++i)
			if (f[i]==1) ++ans1;
		sort(d+1,d+1+nc,cmpr);
		ans2 = 0;
		pre = 0;
		p[m+1] = 1000000+Eps;
		for (int i=1;i<=nc;++i)
		{
			if (p[pre]<d[i].lp)
			{
				++ans2;
				while (p[pre]<=d[i].rp) ++pre;
				--pre;
			}
		}
		printf("%d %d\n",ans1,m-ans2);
	}
    return 0;
}
