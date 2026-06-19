#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,a[1003][1003],vis[1003][1003];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char s;
				cin>>s;
				if(s=='x')a[i][j]=1;
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0&&a[x][y+1]==0&&1<=y+1&&y+1<=m){
				vis[x][y+1]=1;
				y++;
			}
			else if(d==1&&a[x+1][y]==0&&1<=x+1&&x+1<=n){
				vis[x+1][y]=1;
				x++;
			}
			else if(d==2&&a[x][y-1]==0&&1<=y-1&&y-1<=m){
				vis[x][y-1]=1;
				y--;
			}
			else if(d==3&&a[x-1][y]==0&&1<=x-1&&x-1<=n){
				vis[x-1][y]=1;
				x--;
			}else{
				d=(d+1)%4;
			}
		}int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
}
