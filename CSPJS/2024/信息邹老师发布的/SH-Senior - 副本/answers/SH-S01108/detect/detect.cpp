#include<bits/stdc++.h>
using namespace std;
using pll=pair<long long,long long>;
long long n,m,len,vlm;
const long long maxn=1e6+15;
long long c[5010];
long long p[5010];
long long d[5010],v[5010],a[5010];
long long mp[5010];
bool vis[5010];
long long pm[5010];
vector<long long>dct[5010];
long long qa=0;
long long dres=1e18;
void dfs(long long dep)
{
	if(dep==m+1)
	{
		long long num=0;
		for(int i=1;i<=m;i++)
		{
			if(vis[i])
			{
				num++;	
			}	
		}
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			bool ok=0;
			for(auto now:dct[i])
			{
				if(vis[now])
				{
					ok=1;
				}
			}
			if(ok)
			{
				cnt++;
			}
		}
		if(cnt==qa)
		{
			dres=min(dres,num);
		}
		return;
	}
	vis[dep]=1;
	dfs(dep+1);
	vis[dep]=0;
	dfs(dep+1);
	vis[dep]=0;
}
void calc()
{
	dfs(1);
	printf("%lld\n",m-dres);
}
void solvebl()
{
	qa=0;
	dres=1e18;
	for(int i=1;i<=m;i++)
	{
		vis[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		dct[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&p[i]);
	}
	for(int i=1;i<=n;i++)
	{
		bool exd=0;
		for(int j=1;j<=m;j++)
		{
			if(p[j]<d[i])
			{
				continue;
			}
			long long lf=vlm*vlm-2*a[i]*(p[j]-d[i]);
			long long rf=v[i]*v[i];
			if(lf<rf)
			{
				exd=1;
				dct[i].push_back(j); 
			}
		}
		if(exd)
		{
			//cerr<<"CAR "<<i<<" HAS EXDED THE SPLIM! "<<endl;
			for(auto now:dct[i])
			{
				//cerr<<"[LOG] AT: "<<p[now]<<""<<endl;
			}
		}
		qa+=exd;
	}
	printf("%lld ",qa);
	calc();
}
bool cmp(long long x,long long y)
{
	return dct[x].size()<dct[y].size(); 
}
void solve()
{
	qa=0;
	for(int i=1;i<=n;i++)
	{
		dct[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		mp[i]=0;
		vis[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&p[i]);
	}
	for(int i=1;i<=n;i++)
	{
		bool exd=0;
		for(int j=1;j<=m;j++)
		{
			if(p[j]<d[i])
			{
				continue;
			}
			long long dist=(p[j]-d[i]);
			if(a[i]<0)
			{
				if(dist*(-2ll)*a[i]>v[i]*v[i])
				{
					continue;
				}
			}
			long long lf=v[i]*v[i]+2ll*a[i]*dist;
			long long rf=vlm*vlm;
			if(lf>rf)
			{
				exd=1;
				dct[i].push_back(j); 
			}
		}
		if(exd)
		{
			qa++;
			//cerr<<"CAR "<<i<<" HAS EXDED THE SPLIM! "<<endl;
			for(auto now:dct[i])
			{
				//cerr<<"[LOG] AT: "<<p[now]<<""<<endl;
				mp[now]++;
			}
		}
	}
	printf("%lld ",qa);
	for(int i=1;i<=n;i++)
	{
		pm[i]=i;
	}
	sort(pm+1,pm+n+1,cmp);
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		long long cur=pm[i];
		if(dct[cur].size()==0)
		{
			continue;
		}
		bool ok=0;
		long long maxx=-1e18,which=0;
		for(auto now:dct[cur])
		{
			if(vis[now]==1)
			{
				ok=1;
				break;
			}
			else
			{
				if(mp[now]>maxx)
				{
					maxx=mp[now];
					which=now;
				}
			}
		}
		if(!ok)
		{
			vis[which]=1;
			cnt++;
		}
	}
	printf("%lld\n",m-cnt);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&len,&vlm);
		if(n<=20&&m<=20)
		{
			solvebl();
		}
		else if(n<=3000&&m<=3000)
		{
			solve();
		}
	}
	return 0;	
}
