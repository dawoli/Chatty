#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,xx,yy,ans;
char mp[1005][1005];
char vis[1005][1005];
int dd[10][5]={{0,1},{1,0},{0,-1},{-1,0}};
char c1,c2;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		vis[x][y]=1;
		while(k--){
			xx=x+dd[d][0];
			yy=y+dd[d][1];
			if(xx<1 || xx>n || yy<1 || yy>m || mp[xx][yy]=='x'){
				d=(d+1)%4;
			}
			else{
				x=xx;
				y=yy;
				vis[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=vis[i][j];
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
