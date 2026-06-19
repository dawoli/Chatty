#include<bits/stdc++.h>
using namespace std;
int n,m,k,T,ans,x0,y0,d0,dx[]={0,1,0,-1},dy[]={1,0,-1,0},vis[1005][1005];
map<string,int> mp;
char c[1005][1005];
bool check(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m&&c[x][y]=='.')return 1;
	else return 0;
}
void dfs(int x,int y,int d,int step){
	if(step==k+1){
		return ;
	}
	int nx=x+dx[d];
	int ny=y+dy[d];
	if(check(nx,ny)){
		vis[x][y]=1;
		dfs(nx,ny,d,step+1);
	}else{
		dfs(x,y,(d+1)%4,step+1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)cin>>c[i][j],vis[i][j]=0;
		}
		vis[x0][y0]=1;
		dfs(x0,y0,d0,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
