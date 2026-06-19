#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k,q,r[100005],c[100005],f[200005];//vis[200005];
vector <int> s[100005],p[200005];
void input()
{
	cin>>n>>k>>q;
	for(ll i = 1;i <= n;i++)
	{
		ll l;
		cin>>l;
		for(ll j = 1;j <= l;j++)
		{
			ll x;
			cin>>x;
			s[i].push_back(x);
		}
	}
	for(ll i = 1;i <= q;i++)
	{
		cin>>r[i]>>c[i];
	}
}
bool bfs(ll x,ll pos)
{
	queue <ll> qe;
	qe.push(x);
	bool ok = 0;
	f[x] = 0;
	while(!qe.empty())
	{
		ll now = qe.front();
		qe.pop();
//		cout<<now<<" "<<f[now]<<endl;
		if(now == 1 && f[now] == pos && f[now] != 0)
		{
			ok = 1;
			break;
		}
		if(f[now] > pos) break;
		for(ll i = 0;i < p[now].size();i++)
		{
			f[p[now][i]] = f[now] + 1;
			qe.push(p[now][i]);
		}
	}
//	cout<<endl;
	return ok;
}
void solve()
{
	for(ll i = 1;i <= n;i++)
	{
		for(ll j = 0;j < s[i].size();j++)
		{
			for(ll x = 1;x < k;x++)
			{
				if(j + x >= s[i].size()) break;
				p[s[i][j + x]].push_back(s[i][j]);
			}
		}
	}
	for(ll w = 1;w <= q;w++)
	{
//		for(ll i = 1;i <= n;i++)
//		{
//			for(ll j = 1;j <= s[i].size();j++)
//			{
//				vis[s[i][j]] = 0;
//			}
//		}
		if(bfs(c[w],r[w])) cout<<1<<endl;
		else cout<<0<<endl;
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(ll i = 1;i <= n;i++)
		{
			ll l;
			cin>>l;
			for(ll j = 1;j <= l;j++)
			{
				ll x;
				cin>>x;
				s[i].push_back(x);
			}
		}
		for(ll i = 1;i <= q;i++)
		{
			cin>>r[i]>>c[i];
		}
		solve();
	}
	return 0;
}
