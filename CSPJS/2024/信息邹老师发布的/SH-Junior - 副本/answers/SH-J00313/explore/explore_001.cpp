#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int x,y,d,ans;
char g[1003][1003];
int vis[1003][1003];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		ans=1;
		
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>g[i][j];
				
		for(int i=1;i<=k;i++){
			int cx,cy;
			if(d==0){
				cx=x;cy=y+1;
			}else if(d==1){
				cx=x+1;cy=y;
			}else if(d==2){
				cx=x;cy=y-1;
			}else if(d==3){
				cx=x-1;cy=y;
			}
			
			if(cx>=1&&cx<=n&&cy>=1&&cy<=m && g[cx][cy]=='.'){
				x=cx,y=cy;
				if(!vis[cx][cy]){
					ans++;
					vis[cx][cy]=1;
				}
			}
			else d=(d+1)%4;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
