
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+100;
ll n,m,k,ans=INT_MAX,ji;
ll a[11][N];
struct Node{
	ll u,v,w;
	bool operator<(const Node &t) const{
		return w>t.w;
	}
};
vector<pair<ll,ll> > road[N];
bool vis[N];
void solve(){
	memset(vis,0,sizeof(vis));
	priority_queue<Node> q;
	for(auto v:road[1]){
		q.push({1,v.first,v.second});
	}
	vis[1]=1;
	ll rec=1;
	while(!q.empty()){
		Node lns=q.top();
		q.pop();
		if(vis[lns.u]&&vis[lns.v]) continue;
		ji+=lns.w;
		vis[lns.v]=1;
		if(1<=lns.v && lns.v<=n) rec++;
		if(rec==n) break;
		for(auto v:road[lns.v]){
			if(vis[v.first]) continue;
			q.push({lns.v,v.first,v.second});
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		road[u].push_back({v,w});
		road[v].push_back({u,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>a[i][0];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			road[i+n].push_back({j,a[i][j]});
		}
	}
	for(ll i=0;i<(1<<k);i++){
		ji=0;
		for(ll j=0;j<k;j++){
			if((i>>j)&1){
				ji+=a[j+1][0];
				for(ll k=1;k<=n;k++){
					road[k].push_back({n+j+1,a[j+1][k]});
				}
			}
		}
		solve();
		ans=min(ans,ji);
		if(i==(1<<k)-1) break;
		for(ll j=0;j<k;j++){
			if((i>>j)&1){
				for(ll k=1;k<=n;k++){
					road[k].pop_back();
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
