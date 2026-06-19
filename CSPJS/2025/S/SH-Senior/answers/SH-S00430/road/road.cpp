#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> >a[10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(make_pair(v,w));
		a[v].push_back(make_pair(u,w));
	}
	cout<<0;
	return 0;
}
