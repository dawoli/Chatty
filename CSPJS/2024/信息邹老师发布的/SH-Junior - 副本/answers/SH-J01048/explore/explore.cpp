#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,k,x,y,d,ans,vis[1010][1010];
char map1[1010][1010];
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>map1[i][j];
		for(int i=1;i<=k;i++){
			if(vis[x][y]==0)vis[x][y]=1,ans++;
			if(d==0){
				if(y+1<=m&&map1[x][y+1]=='.')y++;
				else d++;
			}
			else if(d==1){
				if(x+1<=n&&map1[x+1][y]=='.')x++;
				else d++;
			}
			else if(d==2){
				if(y-1>=1&&map1[x][y-1]=='.')y--;
				else d++;
			}
			else if(d==3){
				if(x-1>=1&&map1[x-1][y]=='.')x--;
				else d=0;
			}
			if(vis[x][y]==0)vis[x][y]=1,ans++;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
