#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
struct Node
{
	int l,r;
};
ll n,k,a[N],x[N];
ll ans=0;
vector<ll> cnt[2000009];
vector<Node> lr;
bool all1()
{
	for(int i=1;i<=n;i++)
	  if(a[i]!=1)return 0;
	return 1;
}
bool all01()
{
	for(int i=1;i<=n;i++)
	  if(a[i]!=1&&a[i]!=0)return 0;
	return 1;
}
bool cmp(const Node &x,const Node &y)
{
	return x.r<y.r||x.r==y.r&&x.l>y.l;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],x[i]=x[i-1]^a[i];
	if(all1())
	{
		if(k==0)
		  cout<<n/2;
		else
		  cout<<n;
		return 0;
	}
	if(all01())
	{
		ll cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==1)cnt++;
		if(k==0)
		{
			ans=n-cnt;
			for(int i=1;i<n;i++)
			  if(a[i]==1&&a[i+1]==1)
				ans++,a[i]=a[i+1]=0;
			cout<<ans;
		}
		else if(k==1)
		{
			cout<<cnt;
		}
		return 0;
	}
	if(n<=1000)
	{
		for(int i=1;i<=n;i++)
		  for(int j=i;j<=n;j++)
			{
				if((x[j]^x[i-1])==k)
				  lr.push_back({i,j});
			}
		sort(lr.begin(),lr.end(),cmp);
		ll r=0;
		for(auto x:lr)
		{
			if(x.l>r)
			{
				ans++;
				r=x.r;
			}
		}
		cout<<ans;
	}
	else
	{
		ans=0;
		for(int i=0;i<=n;i++)cnt[x[i]].push_back(i);
		for(int i=0;i<=2000000;i++)cnt[i].push_back(n+1);
		int l,r,w;
		for(int i=1;i<=n;i++)
		{
			l=i;
			r=n+1;
			w=(x[i-1]^k);
			if(cnt[w].size()!=0)
			  r=*lower_bound(cnt[w].begin(),cnt[w].end(),i);
			if(r<=n)
			  lr.push_back({l,r});
		}
		sort(lr.begin(),lr.end(),cmp);
		r=0;
		for(auto x:lr)
		{
			if(x.l>r)
			{
				ans++;
				r=x.r;
			}
		}
		cout<<ans;
	}
	return 0;
}

