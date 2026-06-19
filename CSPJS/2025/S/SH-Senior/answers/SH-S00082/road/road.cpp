#include<bits/stdc++.h>
using namespace std;

void FileIO(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
bool mbe;

#define ll long long
const int N=1e5+5;

int n,m,k,c[15],a[15][N];
struct edge{
	int u,v;
	ll w;
	int b;
};
vector<edge> e;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[N];
int Find(int x){
	return fa[x]==x? x:fa[x]=Find(fa[x]);
} 
bool vis[15];
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		e.push_back({u,v,w,-1});
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) flag=1;
		for(int j=1;j<=n;j++) cin>>a[i][j]; 
	}
	
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) for(int k=j+1;k<=n;k++){
		e.push_back({j,k,c[i]+a[i][j]+a[i][k],i});
	} 	
	sort(e.begin(),e.end(),cmp);
	int cnt=0;
	ll ans=0;
	for(int i=0;i<e.size();i++){
		if(cnt==n-1) break; 
		int fu=Find(e[i].u),fv=Find(e[i].v);
		if(fu==fv) continue;
		fa[fu]=fv,cnt++,ans+=e[i].w;
	}
	cout<<ans<<"\n";
	
	return;
}

bool med;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	FileIO();
	
	int T=1;
	while(T--){
		solve();
	}
 	
	return 0;
} 
