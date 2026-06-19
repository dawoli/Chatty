#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int t,n,m,k,x,y,d,ans;
char mp[N][N];bool vis[N][N];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for (int i=1; i<=n; i++)
			scanf("%s",mp[i]+1);
		memset(vis,false,sizeof vis);
		ans=0,vis[x][y]=true;
		while (k--) {
			int xx=-1,yy=-1;
			if (d==0) xx=x,yy=y+1;
			else if (d==1) xx=x+1,yy=y;
			else if (d==2) xx=x,yy=y-1;
			else if (d==3) xx=x-1,yy=y;
			if (xx>=1 && xx<=n && yy>=1 && yy<=m &&
				mp[xx][yy]=='.') x=xx,y=yy;
			else d=(d+1)%4;
			vis[x][y]=true;
		}
		for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (vis[i][j]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
