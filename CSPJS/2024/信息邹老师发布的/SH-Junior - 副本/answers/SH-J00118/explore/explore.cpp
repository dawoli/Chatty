#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		char map[1006][1006]={};
		bool vis[1006][1006]={};
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		cin>>map[i][j];
		vis[x][y]=1;
		while(k--){
			int nx,ny;
			if(d==0){
				nx=x,ny=y+1;
			}else if(d==1){
				nx=x+1,ny=y;
			}else if(d==2){
				nx=x,ny=y-1;
			}else if(d==3){
				nx=x-1,ny=y;
			}
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&map[nx][ny]=='.'){
				x=nx,y=ny;
				//cout<<nx<<" "<<ny<<endl;
				vis[x][y]=1;
			}else{
				d=(d+1)%4;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(vis[i][j])cnt++;
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
