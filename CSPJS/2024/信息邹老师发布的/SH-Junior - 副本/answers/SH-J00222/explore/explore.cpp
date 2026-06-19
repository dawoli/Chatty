#include<bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool vis[1001][1001];
void dfs(int x,int y,int d,int n,int m,int k){
	vis[x][y]=1;
	int nx=x,ny=y;
	if(d==0)nx++;
	if(d==1)ny--;
	if(d==2)nx--;
	if(d==3)ny++;
	if(!vis[nx][ny]&&1<=nx&&nx<=n&&1<=ny&&ny<=m&&grid[nx][ny]=='.'){
		k--;
		dfs(nx,ny,d,n,m,k);
	}else{
		int nd=(d+1)%4;
		k--;
		dfs(nx,ny,nd,n,m,k);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				grid[i][j]=0;
				vis[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>grid[i][j];
			}
		}
		dfs(x,y,d,n,m,k);
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!vis[i][j])cnt++;
			}
		}cout<<cnt;
	}
	return 0;
} 
/*
1
1 5 4
1 1 2
....x

1
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
