#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10024;
ll sn,n,m,k;
struct Edge{
	ll v,w;
	bool operator < (const Edge b) const{
		return b.w<w;
	}
};
ll cnt;
ll vis[N],extraisopen[15];
ll extranc[15],extrae[15][N];
vector<Edge> edge[N],extraedge[15];
ll shortest_road_1(ll st){
	priority_queue<Edge,vector<Edge>> pq;
	memset(vis,0,sizeof(vis));
	for(Edge v:edge[st]){
		pq.push(v);
	}
	vis[st]=1;
	ll ct=0,u,w;
	while(!pq.empty()){
		Edge e=pq.top();
		pq.pop();
		if(vis[e.v]){
			continue;
		}
		u=e.v,w=e.w;
		ct+=w;
		vis[u]=1;
		for(Edge v:edge[u])if(!vis[v.v]){
			pq.push(v);
		}
	}
	return ct;
}
/*
ll shortest_road_2(ll st){
	priority_queue<Edge,vector<Edge>> pq;
	memset(vis,0,sizeof(vis));
	if(st<=N){
		for(Edge v:edge[st]){
			pq.push(v);
		}
		for(int i=1;i<=k;i++)if(!vis[i+N]&&extraisopen[i]){
			pq.push({i+N,extrae[i][st]});
		}
	}else{
		ll h=st-N;
		if(extraisopen[h]){
			for(int i=1;i<=k;i++){
				pq.push({i,extrae[h][i]});
			}
		}
	}
	vis[st]=1;
	ll ct=0,u,w;
	while(!pq.empty()){
		Edge e=pq.top();
		pq.pop();
		if(vis[e.v]){
			continue;
		}
		u=e.v,w=e.w;
		ct+=w;
		vis[u]=1;
		if(u<=N){
			for(Edge v:edge[u])if(!vis[v.v]){
				pq.push(v);
			}
			for(int i=1;i<=k;i++)if(!vis[i+N]&&extraisopen[i]){
				pq.push({i+N,extrae[i][u]});
			}
		}else{
			ll h=st-N;
			if(extraisopen[h]){
				for(int i=1;i<=n;i++)if(!vis[i]){
					pq.push({i,extrae[h][i]});
				}
			}
		}
	}
	return ct;
}*/
ll get_final_answer(int u){
	if(u==k+1){
		return shortest_road_1(1);
	}else{
		ll xa=get_final_answer(u+1);
		edge[++n]=extraedge[u];
		for(int i=1;i<=n;i++){
			edge[i].push_back({u,extrae[u][i]});
		}
		ll xb=get_final_answer(u+1)+extranc[u];
		extraisopen[u]=0;
		n--;
		for(int i=1;i<=n;i++){
			edge[i].pop_back();
		}
		return min(xa,xb);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>sn>>m>>k;
	n=sn;
	ll x,y,c;
	for(ll i=1;i<=m;i++){
		cin>>x>>y>>c;
		edge[x].push_back({y,c});
		edge[y].push_back({x,c});
	}
	bool all_cj_is_zero=1; 
	for(ll i=1;i<=k;i++){
		cin>>c;
		if(c!=0){
			all_cj_is_zero=0;
		}
		extranc[i]=c;
		for(ll j=1;j<=n;j++){
			cin>>x;
			extraedge[i].push_back({j,x});
			extrae[i][j]=x;
		}
	}
	if(k==0){
		cout<<shortest_road_1(1)<<'\n';
	}else if(all_cj_is_zero){
		for(int u=1;u<=k;u++){
			edge[++n]=extraedge[u];
			for(int i=1;i<=sn;i++){
				edge[i].push_back({u,extrae[u][i]});
			}
		}
		cout<<shortest_road_1(1)<<'\n';
	}else{
		cout<<get_final_answer(1)<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

