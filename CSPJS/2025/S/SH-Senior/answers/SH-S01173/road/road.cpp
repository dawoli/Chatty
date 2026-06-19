#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+15;
ll n,m,k,c[N],vis[N],tot=1,cnt[N],jl[N],ans;
struct edge{
	ll u,v,w;
	friend operator<(edge x,edge y){
		return x.w>y.w;
	}
};
vector<edge>e[N];
priority_queue<edge>q;
void BF(){
	vis[1]=1;
	for(auto i:e[1]){
		q.push(i);
	}
	while(tot<n){
		ll u=q.top().u,v=q.top().v,w=q.top().w;
		q.pop();
		if(vis[v])continue;
		ans+=w;
		vis[v]=1;
		tot++;
		for(auto i:e[v]){
			if(vis[i.v])continue;
			q.push(i);
		}
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({u,v,w});
		e[v].push_back({v,u,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i+n];
		for(ll j=1;j<=n;j++){
			ll w;
			cin>>w;
			e[n+i].push_back({n+i,j,w});
			e[j].push_back({j,n+i,w});
		}
	}
	if(k==0){
		BF();
		return 0;
	}
	vis[1]=1;
	for(auto i:e[1]){
		if(i.v<=n)q.push(i);
		else q.push({i.u,i.v,i.w+c[i.v]});
	}
	while(tot<n){
		ll u=q.top().u,v=q.top().v,w=q.top().w;
		q.pop();
		if(vis[v])continue;
		
//		cout<<u<<' '<<v<<' '<<w<<endl;
//		cout<<tot<<endl;
		
		if(v<=n){
			if(u>n)cnt[u]++;
			ans+=w;
			vis[v]=1;
			tot++;
			for(auto i:e[v]){
				if(vis[i.v])continue;
				if(i.v<=n)q.push(i);
				else q.push({i.u,i.v,i.w+c[i.v]});
			}
		}
		else{
			ans+=w;
			vis[v]=1;
			cnt[v]++;
			jl[v]=w;
			for(auto i:e[v]){
				if(vis[i.v])continue;
				q.push(i);
			}
		}
	}
	for(ll i=1;i<=k;i++){
//		cout<<cnt[n+i]<<endl;
		if(cnt[n+i]==1)ans-=jl[n+i];
	}
	cout<<ans;
	return 0;
}
