#include<bits/stdc++.h>
using namespace std;
int T;char mp[1010][1010];
bool vis[1010][1010];
int n,m,x,y,d,k;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			cin>>(mp[i]+1);
		}
		vis[x][y]=1;
		while(k--){
			int xp,yp;
			if(d==0) xp=x,yp=y+1;
			if(d==1) xp=x+1,yp=y;
			if(d==2) xp=x,yp=y-1;
			if(d==3) xp=x-1,yp=y;
			if(1<=xp&&xp<=n&&1<=yp&&yp<=m&&mp[xp][yp]=='.'){
				
				x=xp,y=yp;
				vis[x][y]=1;
			}
			else d=(d+1)%4;
			
		}int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}
