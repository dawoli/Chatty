#include<bits/stdc++.h>
using namespace std;

int T,n,m,k,x,y,d,ans=0;
char a[1005][1005];
int vis[1005][1005];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int r=1;r<=n;r++){
			for(int p=1;p<=m;p++){
				cin>>a[r][p];
			}
		}
		vis[x][y]=1;
		ans++;
	for(int j=1;j<=k;j++){
		if(d==0){
			if(a[x][y+1]=='.'&&y+1<=m){
				y=y+1;
				if(vis[x][y]!=1){
					vis[x][y]=1;
					ans++;
				}
			}
			else {d=(d+1)%4;continue;}
		}
		if(d==1){
			if(a[x+1][y]=='.'&&x+1<=n){
				x=x+1;
				if(vis[x][y]!=1){
					vis[x][y]=1;
					ans++;
				}
			}
			else {d=(d+1)%4;continue;}
		}
		if(d==2){
			if(a[x][y-1]=='.'&&y-1>=1){
				y=y-1;
				if(vis[x][y]!=1){
					vis[x][y]=1;
					ans++;
				}
			}
			else {d=(d+1)%4;continue;}
		}
		if(d==3){
			if(a[x-1][y]=='.'&&x-1>=1){
				x=x-1;
				
				if(vis[x][y]!=1){
					vis[x][y]=1;
					ans++;
				}
			}
			else {d=(d+1)%4;continue;}
		}
	}
	cout<<ans<<endl;
	ans=0;
	for(int u=1;u<=n;u++){
		for(int uu=1;uu<=m;uu++){
			vis[u][uu]=0;
		}
	}
}
	
	return 0;
}
