#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
char a[N][N];
int vis[N][N];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int ans=0;
int m,n,k;
int xx,yy,dd;
bool check(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='x';
}
void dfs(int x,int y,int d,int t){
	if(t>k)return;
	int nx=x+dir[d][0];
	int ny=y+dir[d][1];
	if(check(nx,ny)){
		if(!vis[nx][ny])ans++;
		vis[nx][ny]=1;
		dfs(nx,ny,d,t+1);
	}
	else{
		d=(d+1)%4;
		dfs(x,y,d,t+1);
	}
	return;
}
void solve(){
	memset(a,0,sizeof a);
	memset(vis,0,sizeof vis);
	ans=0;
	cin>>n>>m>>k;
	cin>>xx>>yy>>dd;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	vis[xx][yy]=1;
	ans++;
	dfs(xx,yy,dd,1);
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
