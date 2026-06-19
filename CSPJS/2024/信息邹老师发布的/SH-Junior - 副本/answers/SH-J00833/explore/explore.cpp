#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
int t,n,m,k,sx,sy,sd,ans;
char mp[1010][1010];
bool vis[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void bfs(int sx,int sy,int sd){
	int nx=sx,ny=sy,nd=sd;
	vis[sx][sy]=1;
	for(int i=1;i<=k;i++){
		int tx,ty;
		tx=nx+dx[nd];
		ty=ny+dy[nd];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&mp[tx][ty]=='.'){
			if(vis[tx][ty]==0){
				ans++;
			}
			vis[tx][ty]=1;
			nx=tx;
			ny=ty;
//			printf("%d %d\n",tx,ty);
		}
		else{
			nd++;
			nd%=4;
//			printf("turn to %d\n",nd);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&sx,&sy,&sd);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf(" %c",&mp[i][j]);
			}
		}
		memset(vis,0,sizeof(vis));
		ans=1;
		bfs(sx,sy,sd);
		printf("%d\n",ans);
	}
	return 0;
}
