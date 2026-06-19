#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char ch[1010][1010];
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0},vis[1010][1010];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++) {
		    cin>>ch[i][j];
		    vis[i][j]=0;
		  }
		int ans=1;
		vis[x][y]=1;
		for(int i=1;i<=k;i++) {
			int xx=x+dx[d];
			int yy=y+dy[d];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&ch[xx][yy]=='.') {
				x=xx,y=yy;
				if(vis[xx][yy]==0) {
					vis[xx][yy]=1;
					ans++;
				}
			}
			else {
				d=(d+1)%4;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
