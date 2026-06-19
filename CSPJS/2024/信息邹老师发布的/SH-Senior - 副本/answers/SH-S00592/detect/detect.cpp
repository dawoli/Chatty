#include<bits/stdc++.h>
using namespace std;
const int lenn=1e5+10;
long long int d[lenn],v[lenn],a[lenn],p[lenn],mxd=0,mnp,mxp=0,mxpi;
set<int> pcs[lenn];
long long int n,m,L,V,ans1=0,ans2;
bool emty()
{
	bool flag=0;
	for(int i=1;i<=m;i++)
	{
		if(!pcs[i].empty())
		{
			flag=1;
		}
	}
	return flag;
}
void func()
{
	bool flag1=1,flag2=1;
	scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
	ans2=m;
	ans1=0;
	long long int V2=V*V;
	for(int i=1;i<=n;i++)
	{
		long long int di,vi,ai;
		scanf("%lld%lld%lld",&di,&vi,&ai);
		d[i]=di;
		v[i]=vi;
		a[i]=ai;
		if(ai!=0)
		{
			flag1=0;
		}
		if(ai<=0)
		{
			flag2=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		long long int pi;
		scanf("%lld",&pi);
		p[i]=pi;
	}
	sort(p+1,p+m+1);
	if(flag1)
	{
		for(int i=1;i<=n;i++)
		{
			if(v[i]>V&&d[i]<=p[m])
			{
				ans1++;
			}
		}
		if(ans1!=0)
		{
			ans2--;
		}
		printf("%lld %lld\n",ans1,ans2);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=0)
		{
			if(d[i]<=p[m])
			{
				if((p[m]-d[i])*a[i]*2+v[i]*v[i]>V2)
				{
					mxd=max(mxd,d[i]);
					ans1++;
				}
			}
		}
		else
		{
			double st=d[i]+(V2-v[i]*v[i])/2/a[i];
			bool flag=0;
			for(int j=1;j<=m;j++)
			{
				if(p[j]>=d[i]&&p[j]<st)
				{
					pcs[j].insert(i);
					flag=1;
				}
			}
			if(flag)
			{
				ans1++;
			}
		}
	}
	if(flag2)
	{
		if(ans1!=0)
		{
			ans2--;
		}
		printf("%lld %lld\n",ans1,ans2);
		return;
	}
	for(int i=m;i>=1;i--)
	{
		if(mxd>p[i])
		{
			mnp=i+1;
		}
	}
	bool flag=0;
	ans2=1;
	while(emty())
	{
		mxp=0;
		for(int i=1;i<=m;i++)
		{
			if(mxp<pcs[i].size())
			{
				mxp=pcs[i].size();
				mxpi=i;
			}
		}
		if(mxpi>=mnp&&mxpi<=m)
		{
			flag=1;
		}
		ans2++;
		for(int i=1;i<=m;i++)
		{
			if(i==mxpi||pcs[i].empty())
			{
				continue;
			}
			for(auto it=pcs[mxpi].begin();it!=pcs[i].end();it++)
			{
				auto tmp=pcs[i].find(*it);
				if(tmp!=pcs[i].end())
				{
					pcs[i].erase(tmp);
				}
			}
		}
		pcs[mxpi].clear();
	}
	if(flag)
	{
		ans2--;
	}
	printf("%lld %lld\n",ans1,ans2);
	return;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		func();
	}
	return 0;
}
