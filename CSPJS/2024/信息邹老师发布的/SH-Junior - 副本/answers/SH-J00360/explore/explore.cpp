#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int x0,y0,d0;
char g[1005][1005];
int x,y,d;
int vis[1005][1005];
int cnt;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		x=x0;
		y=y0;
		d=d0;
		cnt=0;
		for(int a=1;a<=n;a++){
			for(int b=1;b<=m;b++){
				g[a][b]='0';
				vis[a][b]=0;
			}
		}
		vis[x][y]=1;
		for(int a=1;a<=n;a++){
			for(int b=1;b<=m;b++){
				cin>>g[a][b];
			}
		}
		for(int j=1;j<=k;j++){
			//cout<<d;
			if(d==0){
				if(x>=1&&y+1>=1&&x<=n&&y+1<=m&&g[x][y+1]=='.'){
					y=y+1;
					vis[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
				continue;
			}
			if(d==1){
				if(x+1>=1&&y>=1&&x+1<=n&&y<=m&&g[x+1][y]=='.'){
					x=x+1;
					vis[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
				continue;
			}
			if(d==2){
				if(x>=1&&y-1>=1&&x<=n&&y-1<=m&&g[x][y-1]=='.'){
					y=y-1;
					vis[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
				continue;
			}
			if(d==3){
				if(x-1>=1&&y>=1&&x-1<=n&&y<=m&&g[x-1][y]=='.'){
					x=x-1;
					vis[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
				continue;
			}
			//cout<<x<<" "<<y<<" "<<d<<endl;
		}
		for(int a=1;a<=n;a++){
			for(int b=1;b<=m;b++){
				if(vis[a][b]==1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
