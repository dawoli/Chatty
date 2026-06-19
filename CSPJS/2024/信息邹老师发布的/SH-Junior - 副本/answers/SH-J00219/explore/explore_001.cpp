#include<bits/stdc++.h>
using namespace std;
#define N 1009
int n,m,k,x,y,d,ans;
int dx[5] = {0,1,0,-1},dy[5] = {1,0,-1,0};
char mp[N][N];
bool vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d %d %d",&n,&m,&k,&x,&y,&d);
		memset(vis,0,sizeof(vis));
		vis[x][y] = 1;
		ans = 1;
		for(int i = 1;i <= n;i++) cin>>(mp[i] + 1);
		while(k--){
			int xx = x + dx[d],yy = y + dy[d];
			if(xx < 1 || xx > n || yy < 1 || yy > m || mp[xx][yy] == 'x') (d += 1) %= 4;
			else x = xx,y = yy;
			if(vis[x][y] == 0) vis[x][y] = 1,ans++;
			//cout<<x<<" "<<y<<" "<<d<<endl; 
		}
		printf("%d\n",ans);
	}
	return 0;
}

