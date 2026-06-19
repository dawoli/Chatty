#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool vis[1001][1001];
int ans=0;
int dis[1001][1001];
int fis[1001][1001];
int fx[5]={0,0,-1,1};
int fy[5]={-1,1,0,0};
int n,m;
int bfs(int x,int y){
	vis[x][y]=1;
	queue<int>q;
	queue<int>p;
	q.push(x),p.push(y);
	while(!q.empty()){
		int vx=q.front();
		int vy=p.front();
		q.pop(),p.pop();
		bool flag=1;
		int g[5],h[5];
		int ans=0;
		for(int i=0;i<4;i++){
			int ux=vx+fx[i],uy=vy+fy[i];
			if(ux>n||ux<1||uy>m||uy<1||vis[ux][uy]||a[ux][uy]=='*') continue;
			if(a[ux][uy]=='.'){
				vis[ux][uy]=1;
				flag=0;
				q.push(ux),p.push(uy);
				dis[ux][uy]=dis[vx][vy]+1;
				fis[ux][uy]=fis[vx][vy];
			}
			else if(a[ux][uy]=='$'&&flag==1){
				g[ans]=ux,h[ans]=uy;
				ans++;
			}
		}
		if(flag==1){
			for(int i=0;i<ans;i++){
				vis[g[i]][h[i]]=1;
				q.push(g[i]),p.push(h[i]);
				dis[g[i]][h[i]]=dis[vx][vy]+1;
				fis[g[i]][h[i]]=fis[vx][vy]+1;
			}
		}
	}
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cin>>a[i][j],vis[i][j]=0,dis[i][j]=0,fis[i][j]=0;
		}
		if(n==1){
			int ans=0;
			for(int i=1;i<=m;i++) if(a[1][i]=='$') ans++;
			cout<<ans<<" "<<m-1<<endl;
		}else{
		bfs(1,1);
		cout<<fis[n][m]<<" "<<dis[n][m]<<endl;
	}
	}
	return 0;
}
