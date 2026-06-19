#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int T,n,m,k,X,Y,D,ans;
int x,y,d;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c[N][N];
bool vis[N][N];
bool check(int x,int y){
	return ((1<=x && x<=n) && (1<=y && y<=m));
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof vis);
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
		vis[x][y]=1,ans=1;
		while(k--){
			if(check(x+dx[d],y+dy[d]) && c[x+dx[d]][y+dy[d]]=='.'){
				x+=dx[d],y+=dy[d];
				if(!vis[x][y]) vis[x][y]=1,ans++;
			}else d=(d+1)%4;
		}
		printf("%d\n",ans);
	}
	return 0;
}
