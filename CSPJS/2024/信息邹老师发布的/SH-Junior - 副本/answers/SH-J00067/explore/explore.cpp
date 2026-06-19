#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
char mm[1007][1007];
bool vis[1007][1007];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int ans[1007];
void dfs(int x,int y,int d,int cnt){
	vis[x][y]=1;
	if(cnt==k+1){
		return;
	}
	int nx=x+dx[d],ny=y+dy[d];
	if(nx<1 || nx>n || ny<1 || ny>m || mm[nx][ny]=='x'){
		d=(d+1)%4;
		dfs(x,y,d,cnt+1);
	}else{
		dfs(nx,ny,d,cnt+1);
	}
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int kk=1;kk<=t;kk++){
		cin>>n>>m>>k;
		int x,y,d,cnt=0;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mm[i][j];
				vis[i][j]=0;
			}
		}
		dfs(x,y,d,1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]) cnt++;
			}
		}
		ans[kk]=cnt;
	}
	for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
}
