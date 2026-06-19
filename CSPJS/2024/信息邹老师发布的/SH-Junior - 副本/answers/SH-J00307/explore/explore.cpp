#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,k;
char mp[1010][1010];
bool vis[1010][1010];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		vis[x0][y0]=1;
		for(int i=1;i<=k;i++){
			int tx=x0+dx[d0];
			int ty=y0+dy[d0];
			if(tx>n||tx<1||ty<1||ty>m||mp[tx][ty]=='x'){
				d0=(d0+1)%4; 
				continue;
			}
			x0=tx,y0=ty;
			vis[tx][ty]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

