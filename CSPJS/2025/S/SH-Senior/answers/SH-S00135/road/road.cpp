#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
#define ll long long
#define PII pair<ll,ll>
ll n,m,k;ll c[15];
ll a[15][N];
vector<PII>e[N];
ll ans;
ll d[N],vis[N];
void prim(ll s){
	memset(d,0x3f,sizeof d);
	d[s]=0;
	priority_queue<PII>q;
	q.push({0,s});
	while(!q.empty()){
		ll a=q.top().second;q.pop();
		if(vis[a])continue;
		vis[a]=1;ans+=d[a];
		int len=e[a].size();
		for(ll i=0;i<len;i++){
			PII x=e[a][i];
			ll v=x.first,w=x.second;
			if(d[v]>w)d[v]=w,q.push({-d[v],v});
		}
	} 
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	bool flag=0;
	if(k==0){
		prim(1);
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];if(c[i])flag=1;
		for(ll j=1;j<=n;j++)cin>>a[i][j];
	}
	if(!flag){
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				for(ll k=1;k<=n;k++){
					if(j==k)continue;
					e[j].push_back({k,a[i][j]+a[i][k]});
				}
			}
		}
		prim(1);
		cout<<ans;
		return 0;
	}
	else if(flag){
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				for(ll k=1;k<=n;k++){
					if(j==k)continue;
					e[j].push_back({k,a[i][j]+a[i][k]+c[i]});
				}
			}
		}
		prim(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
