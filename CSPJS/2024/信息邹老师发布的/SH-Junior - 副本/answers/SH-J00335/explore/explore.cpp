#include<bits/stdc++.h>
using namespace std;
#define N 1005
char ma[N][N];
bool vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(ma,sizeof(ma),'x');
		memset(vis,sizeof(vis),0);
		int n,m,k,x0,y0,d0;
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ma[i][j];
			}
		}
		int x=x0,y=y0,d=d0;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(ma[x][y+1]=='.'){
					y++;
					vis[x][y]=1;
					continue;
				}
			}
			if(d==1){
				if(ma[x+1][y]=='.'){
					x++;
					vis[x][y]=1;
					continue;
				}
			}
			if(d==2){
				if(ma[x][y-1]=='.'){
					y--;
					vis[x][y]=1;
					continue;
				}
			}
			if(d==3){
				if(ma[x-1][y]=='.'){
					x--;
					vis[x][y]=1;
					continue;
				}
			}
			d=(d+1)%4;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1){
					cnt++;
				}
			}
		}
		cout<<cnt+1<<endl;
	}
	return 0;
}
