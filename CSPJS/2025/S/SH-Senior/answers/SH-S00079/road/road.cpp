#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll,ll> PII;

struct edge{
	PII g;
	ll w;
};

bool cmp(edge a,edge b){
	return a.w<b.w;
}

const ll maxn=1e4+20;
ll n,m,k,u0,v0,w0,fa[maxn],c,ans=0;
vector<edge> q;

ll find(ll x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}

#define fi first
#define se second

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u0>>v0>>w0;
		q.push_back((edge){make_pair(u0,v0),w0});
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>w0;
			q.push_back((edge){make_pair(i+n,j),w0});
		}
	}
	sort(q.begin(),q.end(),cmp);
	int sz=q.size();
	for(int i=0;i<sz;i++){
		PII g0=q[i].g;
		int w00=q[i].w;
		int u=g0.fi,v=g0.se;
		u=find(u),v=find(v);
		if(u!=v){
			fa[u]=v;
			ans+=w00;
		}
	}
	cout<<ans;
}
