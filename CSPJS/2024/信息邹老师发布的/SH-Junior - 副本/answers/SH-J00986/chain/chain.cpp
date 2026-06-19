#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const ll N=200009;
ll n,k,q;
ll l[N],r[N],c[N],to[N];
ll mst;
ll node[N]={1},num;
bool ans;
vector<ll> match[N];
vector<ll> s[N];
vector<ll> e[N];
set<ll> step[N];
void dfs(ll x,ll st)
{
	if(st>mst)return;
	if(x!=0)
	  step[x].insert(st);
	for(auto tmp:e[x])
	{
		dfs(tmp,st+1);
	}
}
signed main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll T;
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>q;
		num=0;
		for(ll i=1;i<=2e5;i++)
		  match[i].clear();
		//建点 
		for(ll i=1;i<=n;i++)
		{
			s[i].clear();
			cin>>l[i];
			for(ll j=1;j<=l[i];j++)
			{
				ll x;
				cin>>x;
				node[++num]=x;
				match[x].push_back(num);
				s[i].push_back(x);
				if(j==1)to[i]=num;
			}
		}
/*		for(ll i=0;i<=num;i++)cout<<node[i]<<" ";
		cout<<endl;
		cout<<match[1].size()<<" ";
		for(auto t:match[1])cout<<t<<" ";
		cout<<endl;
		cout<<match[2].size()<<" ";
		for(auto t:match[2])cout<<t<<" ";
		cout<<endl;
		cout<<match[4].size()<<" ";
		for(auto t:match[4])cout<<t<<" ";
		cout<<endl;
		cout<<match[6].size()<<" ";
		for(auto t:match[6])cout<<t<<" ";
		cout<<endl;
		cout<<match[7].size()<<" ";
		for(auto t:match[7])cout<<t<<" ";
		cout<<endl;*/
		//建边 
		to[n+1]=2e5+1;
		for(ll i=1;i<=num;i++)//2e3
		{
			e[i].clear();
			step[i].clear();
			for(ll j=1;j<=n;j++)//1e3
			{
				if(i>=to[j]&&i<to[j+1])continue;
				for(ll t=0;t<s[j].size();t++)//2e3
					if(s[j][t]==node[i])
						for(ll tmp=0;tmp<k;tmp++)
						  if(t+tmp<s[j].size())
							e[i].push_back(to[j]+t+tmp);
			}
		}
		//计算 
		for(ll i=1;i<=q;i++)
		{
			cin>>r[i]>>c[i];
		}
		mst=*max_element(r+1,r+1+q);
		dfs(0,0);
		ans=0;
		for(ll i=1;i<=q;i++)
		{
			for(auto t:match[c[i]])
			  ans=ans||bool(step[t].count(r[i]));
			cout<<ans<<endl;
		}
	}
	return 0;
}

