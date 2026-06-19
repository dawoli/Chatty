#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int n,m,k,x,y,d,pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int times=0;times<t;times++){
		int cnt=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				vis[i][j]=0;				
			}
		vis[x][y]=1;
		for(int i=0;i<k;i++){
			int nx=x+pos[d][0],ny=y+pos[d][1];
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mp[nx][ny]=='.'){
				if(!vis[nx][ny]){
					cnt++;
					vis[nx][ny]=1;	
				}
				x=nx;
				y=ny;
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
