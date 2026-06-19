#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char c;
bool a[1005][1005],vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=0;
		memset(a,false,sizeof(a));
		memset(vis,false,sizeof(vis));
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c=='.')a[i][j]=1;
			}
		}
		for(int i=1;i<=k;i++){
			if(a[x+dir[d][0]][y+dir[d][1]]==1){
				x+=dir[d][0];
				y+=dir[d][1];
				vis[x][y]=1;
			}
			else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==true)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
