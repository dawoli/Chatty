#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define N 1003
int T;
int n,m,k;
int x,y,d;
char g[N][N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[N][N];
int ans;
void init() {
	memset(vis,0,sizeof(vis));
	ans=0;
}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		init();
		scanf("%d\n%d\n%d\n%d\n%d\n%d",&n,&m,&k,&x,&y,&d);
		for(int i=1;i<=n;i++)
			scanf("%s",&g[i]);
		while(k--) {
			if(!vis[x][y]) {
				vis[x][y]=true;
				ans++;
			}
			int tx=x+dx[d],ty=y+dy[d];
			if(tx<1||tx>n||ty<1||ty>m || g[tx][ty-1]=='x') d=(d+1)%4;
			else x=tx,y=ty;
		}
		if(!vis[x][y]) ans++;
		printf("%d\n",ans);
	}
	fclose(stdin),fclose(stdout);
	return 0;
} 
