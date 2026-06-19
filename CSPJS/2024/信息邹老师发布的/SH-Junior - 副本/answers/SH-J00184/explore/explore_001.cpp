#include<iostream>
#include<cstring>
using namespace std;
int t;
int n,m,k;
char a[1005][1005];
bool vis[1005][1005];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int x,y,d;
bool check(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void dfs(int x,int y,int d,int k){
	vis[x][y]=true;
	if(k==0) return ;
	for(int i=d;i<=d+3;i++){
		k--;
		int ii=i%4;
		int nx=x+dir[ii][0];
		int ny=y+dir[ii][1];
		if(!check(nx,ny)||a[nx][ny]=='x') continue;
		dfs(nx,ny,ii,k-1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt=0;
		memset(vis,false,sizeof vis);
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(x,y,d,k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==true) cnt++;
			}
		}
		cout<<cnt+1<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
