#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e4+5;

struct Eg
{
	ll u,v,w;
};

bool operator<(Eg a,Eg b)
{
	return a.w<b.w;
}

ll n,m,k,fa[N],mx,ans;
set<Eg> s;
map<ll,ll> mp;

ll find(ll x)
{
	if(fa[x]==x)
	{
		return x;
	}
	mp[fa[x]]--;
	fa[x]=find(fa[x]);
	mp[fa[x]]++;
	return fa[x];
}

void merge(ll x,ll y)
{
	x=find(x);
	y=find(y);
	mp[fa[x]]--;
	mp[y]++;
	fa[x]=y;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
//	cin>>n>>m>>k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		mp[i]=1;
	}
	for(ll i=1,x,y,z;i<=m;i++)
	{
//		cin>>x>>y>>z;
		scanf("%lld%lld%lld",&x,&y,&z);
		s.insert({x,y,z});
	}
//	for(int i=1;i<=k;i++)
//	{
//		
//	}
	ans=0;
	for(auto it:s)
	{
		if(find(it.u)==find(it.v))
		{
			continue;
		}
		merge(it.u,it.v);
		ans+=it.w;
		mx=max(mx,it.w);
		if(mp[find(1)]==n)
		{
			break;
		}
	}
//	ll anss=0;
//	for(auto it:s)
//	{
//		anss+=it.w;
//	}
//	cout<<anss<<endl;
	cout<<ans<<endl;
	return 0;
} 
