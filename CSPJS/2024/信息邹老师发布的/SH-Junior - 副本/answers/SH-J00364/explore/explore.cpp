#include<bits/stdc++.h>
using namespace std;
int q;
char a[1005][1005];
int vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>q;
	while(q--){
		int n,m,k;
		memset(a,'x',sizeof(a));
		memset(vis,0,sizeof(vis));
		int ans=0;
		scanf("%d%d%d",&n,&m,&k);
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vis[x][y]=1;
		ans++;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(a[x][y+1]!='x'&&y+1<=m){
					if(vis[x][y+1]==0){
						ans++;
						vis[x][y+1]=1;
					}
					y++;
				}
				else {
					d=(d+1)%4;
				}
			}
			else if(d==1){
				if(a[x+1][y]!='x'&&x+1<=n){
					if(vis[x+1][y]==0){
						ans++;
						vis[x+1][y]=1;
					}
					x++;
				}
				else {
					d=(d+1)%4;
				}
			}
			else if(d==2){
				if(a[x][y-1]!='x'&&y-1>=1){
					if(vis[x][y-1]==0){
						ans++;
						vis[x][y-1]=1;
					}
					y--;
				}
				else {
					d=(d+1)%4;
				}
			}
			else if(d==3){
				if(a[x-1][y]!='x'&&x-1>=1){
					if(vis[x-1][y]==0){
						ans++;
						vis[x-1][y]=1;
					}
					x--;
				}
				else {
					d=(d+1)%4;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
