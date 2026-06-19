#include<bits/stdc++.h>
using namespace std;
int t,n,vis[100005],ans;
struct S{
	int a,b,c,d,e;
}sa[100005],sb[100005],sc[100005];
bool cmp1(const S& a,const S& b)
{
	return a.d<b.d;
}
bool cmp2(const S& a,const S& b)
{
	return a.d>b.d;
}
bool cmp3(const S& a,const S& b)
{
	return a.e>b.e;
}void dfs(int d,int aa,int bb,int cc,int i)
{
	if(i==n+1) 
	{
		ans=max(ans,d);
		return;
	}else
	{
		
	if(aa<n/2)
	dfs(d+sa[i].a,aa+1,bb,cc,i+1);
	if(bb<n/2)
	dfs(d+sa[i].b,aa,bb+1,cc,i+1);
	if(cc<n/2)
	dfs(d+sa[i].c,aa,bb,cc+1,i+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		cin>>n;int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>sa[i].a>>sa[i].b>>sa[i].c;
			sa[i].d=max(sa[i].a,sa[i].b);sa[i].d=max(sa[i].d,sa[i].c);
			sa[i].e=max(abs(sa[i].a-sa[i].b),abs(sa[i].a-sa[i].c));sa[i].e=max(sa[i].e,abs(sa[i].c-sa[i].b));
		
		}
		if(n<30)
		{
			ans=0;
		dfs(0,0,0,0,1);
		cout<<ans<<endl;
		continue;
		}
		sort(sa+1,sa+1+n,cmp1);
		int ans=0;
		int na=0,nb=0,nc=0;
		for(int i=1;i<=n;i++)
		{
			if(sa[i].d==sa[i].a&&na<n/2)
			{
				na++;ans+=sa[i].d;
			}else if(sa[i].d==sa[i].b&&nb<n/2)
			{
				nb++;ans+=sa[i].d;
			}else if(sa[i].d==sa[i].c&&nc<n/2)
			{
				nc++;ans+=sa[i].d;
			}else if(na>=n/2)
			{
				ans+=max(sa[i].b,sa[i].c);
			}else if(nb>=n/2)
			{
				ans+=max(sa[i].a,sa[i].c);
			}else if(nc>=n/2)
			{
				ans+=max(sa[i].b,sa[i].a);
			}
		}
		sort(sa+1,sa+1+n,cmp2);
		int ans2=0;
		na=0,nb=0,nc=0;
		for(int i=1;i<=n;i++)
		{
			if(sa[i].d==sa[i].a&&na<n/2)
			{
				na++;ans2+=sa[i].d;
			}else if(sa[i].d==sa[i].b&&nb<n/2)
			{
				nb++;ans2+=sa[i].d;
			}else if(sa[i].d==sa[i].c&&nc<n/2)
			{
				nc++;ans2+=sa[i].d;
			}else if(na>=n/2)
			{
				ans2+=max(sa[i].b,sa[i].c);
			}else if(nb>=n/2)
			{
				ans2+=max(sa[i].a,sa[i].c);
			}else if(nc>=n/2)
			{
				ans2+=max(sa[i].b,sa[i].a);
			}
		}
		sort(sa+1,sa+1+n,cmp3);
		int ans3=0;
		na=0,nb=0,nc=0;
		for(int i=1;i<=n;i++)
		{
			if(sa[i].d==sa[i].a&&na<n/2)
			{
				na++;ans+=sa[i].d;
			}else if(sa[i].d==sa[i].b&&nb<n/2)
			{
				nb++;ans+=sa[i].d;
			}else if(sa[i].d==sa[i].c&&nc<n/2)
			{
				nc++;ans+=sa[i].d;
			}else if(na>=n/2)
			{
				ans+=max(sa[i].b,sa[i].c);
			}else if(nb>=n/2)
			{
				ans+=max(sa[i].a,sa[i].c);
			}else if(nc>=n/2)
			{
				ans+=max(sa[i].b,sa[i].a);
			}
		}
		cout<<max(max(ans,ans2),ans3)<<endl;
	}
	return 0;
}
