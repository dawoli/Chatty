#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
bool kk[20];
int d[N][N];
int n,m,k;
int a[N],c[N];
bool vis[N];
int ans=2e9;
vector<int>l[N];
void dfs(int x,int sum,int cnt){
	//cout<<"dfs("<<x<<","<<sum<<","<<cnt<<")"<<endl;
	if(cnt==n){
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans)return;
	for(int i=0;i<l[x].size();i++){
		int y=l[x][i];
		if(vis[y])continue;
		vis[y]=1;
		dfs(y,sum+d[x][y],cnt+1);
		vis[y]=0;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,0x7f,sizeof d);
	cin>>n>>m>>k;
	int u,v,w;
	while(m--){
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=w;
		l[u].push_back(v);
		l[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int x;
		for(int i=1;i<=n;i++)
			cin>>x;
	}
	vis[1]=1;
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}
