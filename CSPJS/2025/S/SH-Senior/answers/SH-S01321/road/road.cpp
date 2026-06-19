#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
struct node{
	int v,w;
	bool operator <(node x)const{
		return w>x.w;
	}
};
int n,m,k,c[15],a[15][N],ans=1e18,sum,addn;
bool vis[N+15],f[N+15];
vector<node>G[N+15];
priority_queue<node>q;
void add(int i){
	for(int i=1;i<=k;i++) f[n+i]=false;
	sum=0;
	int pos=1;
	while(i){
		if(i&1){
			addn++;
			sum+=c[pos];
			f[n+pos]=true;
		}
		pos++;
		i>>=1;
	}
}
void solve(int kk){
	add(kk);
	memset(vis,0,sizeof(vis));
	q.push({1,0});
	int cnt=0;
	while(!q.empty()){
		auto t=q.top();q.pop();
		int u=t.v,w=t.w;
		if(vis[u]) continue;
		vis[u]=true;
		sum+=t.w;
		if(cnt==n+addn-1) break;
		for(auto x:G[u]){
			if(vis[x.v]||!f[x.v]) continue;
			q.push({x.v,x.w});
		}
	}
	ans=min(ans,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u]=f[v]=true;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			G[n+i].push_back({j,a[i][j]});
			G[j].push_back({n+i,a[i][j]});
		}
	}
	for(int i=0;i<1<<k;i++) 
		solve(i);
	cout<<ans<<endl;
}
