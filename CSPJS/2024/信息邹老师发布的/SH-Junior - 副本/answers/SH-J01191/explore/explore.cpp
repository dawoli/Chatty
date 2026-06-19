#include<bits/stdc++.h>
#define maxn 1234
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int t,n,m,k,x,y,d,ans;
char c[maxn][maxn];
bool vis[maxn][maxn];
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		ans=0;
		scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y,&d);
		vis[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)cin>>c[i][j];
		while(k--){
			if(d==0){
				if(x>=1&&x<=n&&(y+1)>=1&&(y+1)<=m&&c[x][y+1]=='.')y++;
				else d=1;
				vis[x][y]=1;
				continue;
			}
			else if(d==1){
				if((x+1)>=1&&(x+1)<=n&&y>=1&&y<=m&&c[x+1][y]=='.')x++;
				else d=2;
				vis[x][y]=1;
				continue;
			}
			else if(d==2){
				if(x>=1&&x<=n&&(y-1)>=1&&(y-1)<=m&&c[x][y-1]=='.')y--;
				else d=3;
				vis[x][y]=1;
				continue;
			}
			if(d==3){
				if((x-1)>=1&&(x-1)<=n&&y>=1&&y<=m&&c[x-1][y]=='.')x--;
				else d=0;
				vis[x][y]=1;
				continue;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vis[i][j]==1)ans++;
		printf("%lld\n",ans);
	}
	return 0;
}

// code written by luogu user #951212
