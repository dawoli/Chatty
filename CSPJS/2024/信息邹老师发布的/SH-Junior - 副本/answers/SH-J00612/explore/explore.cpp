#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,m,k,x,y,d,ans;
int mp[1005][1005],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[1005][1005];
char c;
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				cin>>c;
				if(c=='.')mp[i][j]=1;
				if(c=='x')mp[i][j]=0;
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		ans++;
		for(int i=1;i<=k;i++) {
			x+=dx[d];
			y+=dy[d];
			if(x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]==1) {
				if(vis[x][y]==0)ans++;
				vis[x][y]=1;
			}
			else {
				x-=dx[d];
				y-=dy[d];
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
