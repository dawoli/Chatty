#include<bits/stdc++.h>
using namespace std;
int d[10][10],T,n,m,k,x,y,dis;
char c[1050][1050];
bool vis[7][1050][1050];
void bfs(int k,int x,int y,int dis,int l){
	vis[l][x][y]=1;
	for(int i=1;i<=k;i++){
		int tx=x+d[dis][0],ty=y+d[dis][1];
		if(tx<=n && ty<=m && tx>=1 && ty>=1 && c[tx][ty]=='.')
			vis[l][tx][ty]=1,x=tx,y=ty;
		else
			dis=(dis+1)%4;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cnt+=vis[l][i][j];
	cout<<cnt<<endl;
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	d[0][1]=1,d[1][0]=1,d[2][1]=-1,d[3][0]=-1;
	cin>>T;
	for(int l=1;l<=T;l++){
		cin>>n>>m>>k;
		cin>>x>>y>>dis;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>c[i][j];
		bfs(k,x,y,dis,l);
	}
	return 0;
} 
