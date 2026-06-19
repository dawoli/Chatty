#include<bits/stdc++.h>
using namespace std;

int t;
char a[1005][1005];
bool vis[1005][1005];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,k,x,y,d;
		int ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		while(k--){
			switch(d){
				case 0:{
					if(a[x][y+1]=='.' && y+1<=m){
						y++;
						if(vis[x][y]==0){
							ans++;
							vis[x][y]=1;
						}
					}
					else{
						d=(d+1)%4;
					}
					break;
				}
				case 1:{
					if(a[x+1][y]=='.' && x+1<=n){
						x++;
						if(vis[x][y]==0){
							ans++;
							vis[x][y]=1;
						}
					}
					else{
						d=(d+1)%4;
					}
					break;
				}
				case 2:{
					if(a[x][y-1]=='.' && y-1>=1){
						y--;
						if(vis[x][y]==0){
							ans++;
							vis[x][y]=1;
						}
					}
					else{
						d=(d+1)%4;
					}
					break;
				}
				case 3:{
					if(a[x-1][y]=='.' && x-1>=1){
						x--;
						if(vis[x][y]==0){
							ans++;
							vis[x][y]=1;
						}
					}
					else{
						d=(d+1)%4;
					}
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
