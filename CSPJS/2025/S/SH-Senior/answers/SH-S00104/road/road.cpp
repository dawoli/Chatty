#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int to,w;
};
int g[10005][10005];
bool go[10005][10005],fl[10005];
long long ans=0;
//vector<node> g[10005];
bool f[10005];
int bfs(int s,int e){
	memset(f,0,sizeof(f));
	queue<node> q;
	q.push({s,0});
	f[s]=1;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		if(now.to==e){
			for(int i=1;i<=n;i++) if(f[i]) fl[i]=1;
			return now.w;
		}
		for(int i=1;i<=n;i++){
			if(g[now.to][i]==0) continue;
			if(f[i]) continue;
			q.push({i,now.w+g[now.to][i]});
			f[i]=1;
			go[now.to][i]=1;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(g,0,sizeof(g));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		int a[10005];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			for(int k=j-1;k>=1;k--){
				g[j][k]=min(g[j][k],a[j]+a[k]+c);
				g[k][j]=min(g[k][j],a[j]+a[k]+c);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(fl[i]||fl[j]) continue;
			bfs(i,j);
//			cout<<"a"<<i<<" "<<j<<"a";
		}
	}
//	for(int i=1;i<=n;i++) cout<<fl[i]<<" ";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			cout<<g[i][j]<<" ";
			if(go[i][j]==1){
				ans+=g[i][j];
			}
		}
//		cout<<"\n";
	}
	cout<<ans;
	return 0;
}
