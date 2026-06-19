#include<bits/stdc++.h>
using namespace std;
bool book[1010][1010];
char a[1010][1010];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},n,m;
bool bj(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		int k,x,y,d,cnt=1;
		cin>>n>>m>>k>>x>>y>>d;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin>>a[i][j];
				book[i][j]=0;
			}
		}
		book[x][y]=1;
		while (k--){
			int nx=x+dir[d][0],ny=y+dir[d][1];
			if (bj(nx,ny)&&a[nx][ny]=='.'){
				cnt+=!book[nx][ny];
				book[nx][ny]=1;
				x=nx;y=ny;
			}
			else d=(d+1)%4;
			
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
