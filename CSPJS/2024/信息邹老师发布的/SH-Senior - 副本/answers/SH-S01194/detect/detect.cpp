#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;//?
long long n,m,LLL,VVV;
struct QQ{
	long long l,r;
}qq[maxn];//zhu yi l>r
int p[maxn];
void solve()
{
//	init...
	scanf("%lld%lld%lld%lld",&n,&m,&LLL,&VVV);
	for (long long i=1,d,v,a;i<=n;i++)
	{
		scanf("%lld%lld%lld",&d,&v,&a);
		if (a>0)
		{
			long long X=max((VVV*VVV-v*v)/2/a,0ll);
			while (2*a*X+v*v<=VVV*VVV&&d+X<=LLL)	X++;
			qq[i]={d+X,LLL};
		}
		else if (a==0)
		{
			if (v>VVV)	qq[i]={d,LLL};
			else		qq[i]={1,0};
		}
		else if (a<0)
		{
			if (v<=VVV)	qq[i]={1,0};
			else
			{
				long long X=(VVV*VVV-v*v)/2/a;
				while (2*a*X+v*v>VVV*VVV&&d+X<=LLL)	X++;
				qq[i]={d,min(LLL,d+X-1)};
			}
		}
	}
	sort(qq+1,qq+n+1,[](QQ x,QQ y){return x.r<y.r;});
	
	for (int i=1;i<=m;i++)	scanf("%d",&p[i]);
	
	int che=0,yi=0;
	int da=-1;
	p[0]=-1;
	for (int i=1,j=1;i<=n;i++)
	{
		long long l=qq[i].l,r=qq[i].r;
		if (l>r)	continue;
		if (da>=l)
		{
			che++;
			continue;
		}
		while (j<=m&&p[j]<=r)	j++;
		if (p[j-1]>=l)
		{
			che++,yi++;
			da=max(da,p[j-1]);
		}
	}
	printf("%d %d\n",che,m-yi);
}
int main()
{
//	freopen("detect5.in","r",stdin);
//	freopen("out.out","w",stdout);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;scanf("%d",&T);
	while (T--)	solve();
	return 0;
}
