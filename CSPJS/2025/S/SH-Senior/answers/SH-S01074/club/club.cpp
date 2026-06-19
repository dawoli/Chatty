#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n;
ll a[N][5];
ll f[N];
pair<ll,ll> g[N];
ll ans=0;
int club[3];
bool eq3()
{
	for(int i=1;i<=n;i++)
	  if(a[i][2]!=0)return 0;
	return 1;
}
bool eq2()
{
	for(int i=1;i<=n;i++)
	  if(a[i][1]!=0)return 0;
	return 1;
}
void dfs(int x,ll sum)
{
	if(x==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<=2;i++)
	{
		club[i]++;
		if(club[i]<=n/2)
		  dfs(x+1,sum+a[x][i]);
		club[i]--;
	}
}
bool ia(pair<ll,ll> x)
{
	return x.first<x.second;
}
bool ib(pair<ll,ll> x)
{
	return x.second<x.first;
}
bool cmp1(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
	if(ia(a)&&ia(b))return a.second>b.second||a.second==b.second&&a.first>b.first;
	return a.first>b.first||a.first==b.first&&a.second>b.second;
}
bool cmp2(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
	if(ib(a)&&ib(b))return a.first>b.first||a.first==b.first&&a.second>b.second;
	return a.second>b.second||a.second==b.second&&a.first>b.first;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		if(n<=30)
		{
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		if(eq3())
		{
			if(eq2())
			{
				for(int i=1;i<=n;i++)
				{
					f[i]=a[i][0];
				}
				sort(f+1,f+1+n);
				reverse(f+1,f+1+n);
				for(int i=1;i<=n/2;i++)ans+=a[i][0];
				cout<<ans<<endl;
				continue;
			}
			ans=0;
			ll sum=0;
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++)
			{
				g[i]={a[i][0],a[i][1]};
			}
			sort(g+1,g+1+n,cmp1);
			for(int i=1;i<=n;i++)
			{
				if(g[i].first<g[i].second&&cnt2<n/2)
				  sum+=g[i].second,cnt2++;
				else
				{
					if(cnt1<n/2)
					  sum+=g[i].first,cnt1++;
					else if(cnt2<n/2)
					  sum+=g[i].second,cnt2++;
				}
			}
			ans=max(ans,sum);
			sort(g+1,g+1+n,cmp2);
			cnt1=cnt2=sum=0;
			for(int i=1;i<=n;i++)
			{
				if(g[i].second<g[i].first&&cnt1<n/2)
				  sum+=g[i].first,cnt1++;
				else
				{
					if(cnt2<n/2)
					  sum+=g[i].second,cnt2++;
					else if(cnt1<n/2)
					  sum+=g[i].first,cnt1++;
				}
			}
			ans=max(ans,sum);
			cout<<ans<<endl;
			continue;
		}
		else
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=max({a[i][0],a[i][1],a[i][2]});
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

