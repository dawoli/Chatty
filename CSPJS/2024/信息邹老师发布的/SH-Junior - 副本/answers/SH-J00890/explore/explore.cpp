#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool book[1010][1010];
int dis[4][2]={
0,1,
1,0,
0,-1,
-1,0};
bool bj(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
char a[1010][1010];
int main(){	
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		int x,y,d,cnt=1;
		cin>>x>>y>>d;
		book[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			int nx=x+dis[d][0],ny=y+dis[d][1];
			if(bj(nx,ny)&&a[nx][ny]=='.'){
				x=nx,y=ny;
				if(!book[x][y])cnt++,book[x][y]=1;
			}
			else{
				d++;
				d%=4;
			}
		}
		cout<<cnt<<"\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				book[i][j]=0;
			}
		}
	}
	return 0;
}
