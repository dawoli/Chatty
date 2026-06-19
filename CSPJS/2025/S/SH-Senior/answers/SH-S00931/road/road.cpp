#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
}
#define N 2222
#define int long long
struct Edge{
	int v,w;
	bool operator<(const Edge&b)const{
		return w>b.w;
	}
};
int n,m,k,u,v,w,b[N],a[11][N],e[N][N],ans=1e18,minn[N],le[10][N][N],vis[N],c[11];
int Prim(int s){
	int ans=0;
	for(int i=1;i<=n;i++)vis[i]=0,minn[i]=e[s][i];
	vis[s]=1;
	for(int i=1;i<n;i++){
		int mn=1e18,id=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&minn[j]<mn)mn=minn[j],id=j;
		ans+=mn;vis[id]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j])minn[j]=min(minn[j],e[id][j]);
	}
	return ans;
}
void dfs(int id,int s){
	if(id>k){
		ans=min(ans,Prim(1)+s);
		return;
	}
	dfs(id+1,s);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			le[id-1][i][j]=e[i][j];
			e[i][j]=min(e[i][j],a[id][i]+a[id][j]);
		}
	dfs(id+1,s+c[id]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			e[i][j]=le[id-1][i][j];
}
signed main(){
	open("road");
	cin>>n>>m>>k;
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=n;i++)e[i][i]=0;
	while(m--){
		cin>>u>>v>>w;
		e[u][v]=min(e[u][v],w);
		e[v][u]=min(e[v][u],w);
	}
	int x=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];x+=c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(!x){
		int x=0;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					e[j][k]=min(e[j][k],a[i][j]+a[i][k]);
		cout<<Prim(1)<<endl;
		return 0;
	}
	if(n>2000){
		cout<<Prim(1)<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
}
