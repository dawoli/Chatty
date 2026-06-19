#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+5;
int n,m,k,ans,tmp[20];
bool flag[N],flag1[20];
struct edge{
	int u,v,w;
};
vector<edge>G[N];
bool operator<(edge a,edge b){
	if(a.w==b.w) return a.u<b.u;
	return a.w>b.w;
}
priority_queue<edge> q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w; 
		G[u].push_back({u,v,w});
		G[v].push_back({v,u,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			G[j].push_back({j,n+i,w+c});
			G[n+i].push_back({n+i,j,w});
		}
	}
	flag[1]=true;
	for(auto x:G[1]){
		q.push(x);
	}
	while(!q.empty()){
		auto x=q.top();
		q.pop();
		int u=x.u,v=x.v,w=x.w;
//		cout<<u<<" "<<v<<" "<<w<<endl;
		if(flag[v]) continue;
		if(u>n) flag1[u-n]=true;
		if(v>n) tmp[v-n]=w;
		ans+=w;
		flag[v]=true;
		for(auto awa:G[v]){
			if(flag[awa.v]) continue;
			q.push(awa);
		}
	}
	for(int i=1;i<=k;i++) if(!flag1[i]) ans-=tmp[i];
	cout<<ans;
	return 0;
}

