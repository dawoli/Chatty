#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k,x,y,d;
char g[1003][1003];
bool vis[1003][1003];
long long step;
void dfs(int x,int y,int d,int s) {
	if(s==k) return ;
	s++;
	int nx,ny;
	if(d==0) {
		nx=x,ny=y+1;
	}
	else if(d==1) {
		nx=x+1,ny=y;
	}
	else if(d==2) {
		nx=x,ny=y-1;
	}
	else if(d==3) {
		nx=x-1,ny=y;
	}
	if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&g[nx][ny]=='.') {
		if(!vis[nx][ny]) step++;
		vis[nx][ny]=1;
		dfs(nx,ny,d,s);
	}
	else {
		dfs(x,y,(d+1)%4,s);
	}
}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		step=0;
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				cin>>g[i][j];
			}
		}
		vis[x][y]=1;
		dfs(x,y,d,0);
		printf("%ld\n",step+1);
	}
	return 0;
}
