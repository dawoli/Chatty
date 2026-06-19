#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,xx,yy,vis[1005][1005],ans;
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		ans=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		vis[x][y]=1;
		while(k--){
			xx=x,yy=y;
			if(d==0) yy++;
			else if(d==1) xx++;
			else if(d==2) yy--;
			else if(d==3) xx--;
			if(a[xx][yy]!='.'){
				d++;
				d%=4;
			}else{
				x=xx;
				y=yy;
				vis[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vis[i][j]){
					ans++;
				}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
