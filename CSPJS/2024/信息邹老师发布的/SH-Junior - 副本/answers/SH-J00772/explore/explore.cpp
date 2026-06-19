#include<bits/stdc++.h>
using namespace std;
bool vis[1005][1005]={false};
char a[1005][1005];
int t,n,m,k,x,y,d;
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(vis,false,sizeof(vis));
		int cnt=1;
		scanf("%d %d %d %d %d %d",&n,&m,&k,&x,&y,&d);
		vis[x][y]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)cin>>a[i][j];
		}for(int i=1;i<=k;i++){
			if(d==0){
				if(y<m&&a[x][y+1]!='x'){
					y++;
					if(!vis[x][y])cnt++;
					vis[x][y]=true;
				}else{
					d++;
					d%=4;
				}continue; 
			}if(d==1){
				if(x<n&&a[x+1][y]!='x'){
					x++;
					if(!vis[x][y])cnt++;
					vis[x][y]=true;
				}else{
					d++;
					d%=4;
				}continue; 
			}if(d==2){
				if(y>1&&a[x][y-1]!='x'){
					y--;
					if(!vis[x][y])cnt++;
					vis[x][y]=true;
				}else{
					d++;
					d%=4;
				}continue; 
			}if(d==3){
				if(x>1&&a[x-1][y]!='x'){
					x--;
					if(!vis[x][y])cnt++;
					vis[x][y]=true;
				}else{
					d++;
					d%=4;
				}continue; 
			}
		}printf("%d\n",cnt);
	}
}
