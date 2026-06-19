#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,sx,sy,d,dir[4][2]={0,1,1,0,0,-1,-1,0};
char a[1001][1001];
bool book[1001][1001];
bool bj(int i,int j){
	return i>=1&&i<=n&&j>=1&&j<=m;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){		
		int step=1;
		memset(book,0,sizeof book);
		cin>>n>>m>>k>>sx>>sy>>d;
		book[sx][sy]=1;
		int nx=sx,ny=sy;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(bj(nx+dir[d][0],ny+dir[d][1])&&a[nx+dir[d][0]][ny+dir[d][1]]=='.'){
				int nowx=nx+dir[d][0];
				int nowy=ny+dir[d][1];			
				if(book[nowx][nowy]==0){
					book[nowx][nowy]=1;
					step++;
				}
				nx=nowx,ny=nowy;
			}
			else d=(d+1)%4;
		}	
		cout<<step<<endl;
	}
	return 0;
}
