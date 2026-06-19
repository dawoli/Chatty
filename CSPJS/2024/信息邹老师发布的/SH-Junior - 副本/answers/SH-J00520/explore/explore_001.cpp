#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int ans,vis[1010][1010];
char a[1010][1010]; 
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int _=1;_<=t;++_){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		memset(vis,0,sizeof(vis));
		ans=0;
		x--;
		y--;
		ans=1;
		vis[x][y]=1;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=k;++i){
			if(d==0){
				if(x<0||x>=n||y+1<0||y+1>=m){
					d=(d+1)%4;
				}else if(a[x][y+1]=='x'){
					d=(d+1)%4;
				}else{
					y++;
					if(vis[x][y]==0){
						ans++;
						vis[x][y]=1;
					}
				}
			}else if(d==1){
				if(x+1<0||x+1>=n||y<0||y>=m){
					d=(d+1)%4;
				}else if(a[x+1][y]=='x'){
					d=(d+1)%4;
				}else{
					x++;
					if(vis[x][y]==0){
						ans++;
						vis[x][y]=1;
					}
				}
			}else if(d==2){
				if(x<0||x>=n||y-1<0||y-1>=m){
					d=(d+1)%4;
				}else if(a[x][y-1]=='x'){
					d=(d+1)%4;
				}else{
					y--;
					if(vis[x][y]==0){
						ans++;
						vis[x][y]=1;
					}
				}
			}else if(d==3){
				if(x-1<0||x-1>=n||y<0||y>=m){
					d=(d+1)%4;
				}else if(a[x-1][y]=='x'){
					d=(d+1)%4;
				}else{
					x--;
					if(vis[x][y]==0){
						ans++;
						vis[x][y]=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
