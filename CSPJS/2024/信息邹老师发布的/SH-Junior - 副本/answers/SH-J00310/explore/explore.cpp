#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,xx,yy,d,t,ans,vis[1005][1005],dx[4]{0,1,0,-1},dy[4]{1,0,-1,0};
char c[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>c[i][j];
		memset(vis,0,sizeof(vis)); vis[x][y]=1,ans=1;
		while(k--){
			xx=x+dx[d],yy=y+dy[d];
			if(xx<1||yy<1||xx>n||yy>m||c[xx][yy]=='x') d=(d+1)%4;
			else x=xx,y=yy;
			if(!vis[x][y]) vis[x][y]=1,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
