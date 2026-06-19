/*
CSPS 2025 RP++
Code With Love by Hughpig(646208)
QwQ
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define up(l,r,i) for(int i=(l);i<=(r);++i)
#define pb push_back

ll n,m,k,c[11],a[11][10022],val[10022],minv[10022],ans=1e18;
bool vis[10022];
vector<pair<ll,ll> > G[10022];

inline void prim(){
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
	pq.push(make_pair(0,1));
	memset(val,0x3f,sizeof val);
	memset(vis,0,sizeof vis);val[1]=0;
	while(pq.size()){
		auto tmp=pq.top();pq.pop();
		ll w=tmp.first,u=tmp.second;
		if(w<val[u])val[u]=w;
		if(vis[u])continue;
		vis[u]=1;
		for(auto tmp:G[u]){
			ll v=tmp.first,_w=tmp.second;
			if(vis[v])continue;
			pq.push(make_pair(_w,v));
		}
	}
}

inline void solve(){
	cin>>n>>m>>k;
	up(1,m,i){
		ll u,v,w;cin>>u>>v>>w;
		G[u].pb(make_pair(v,w));
		G[v].pb(make_pair(u,w));
	}memset(minv,0x3f,sizeof minv);
	up(1,k,i){
		cin>>c[i];minv[i]=1e18;
		up(1,n,j)cin>>a[i][j],minv[i]=min(minv[i],a[i][j]);
		//cout<<minv[i]<<" \n"[i==k];
	}
	if(k>0){
		bool flag=1;
		if(c[1])flag=0;
		up(1,n,j)if(a[1][j])flag=0;
		if(flag)cout<<0,exit(0);
	}
	//prim();
	up(0,(1ll<<k)-1,state){
		ll sum=0;
		up(1,k,i){
			if((state>>(i-1))&1){
				sum+=c[i];
				up(1,n,j)G[n+i].pb(make_pair(j,a[i][j])),G[j].pb(make_pair(n+i,a[i][j]));
			}
		}
		//cout<<state<<' ';
		prim();
		//cout<<val[4]<<' ';
		up(1,n+k,i){
			if(i<=n){
				ll v=val[i];
				/*up(1,k,j)if((state>>(j-1))&1)v=min(v,a[j][i]);*/
				sum+=v;
				//if(state==1)cout<<v<<' ';
			}
			else if((state>>(i-n-1))&1){
				//sum+=minv[i-n];
				//if(state==1)cout<<val[i]<<' ';
				sum+=val[i];
			}
		}
		ans=min(ans,sum);
		up(1,k,i){
			if((state>>(i-1))&1){
				up(1,n,j)G[n+i].pop_back(),G[j].pop_back();
			}
		}
		//cout<<state<<' '<<sum<<'\n';
	}
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc=1;
	//cin>>tc;
	while(tc--){
		solve();
	}
}

