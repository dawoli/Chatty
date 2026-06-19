#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c[1005][1005];
bool vis[1005][1005]; 
void dfs(int step,int x,int y,int d){
	while(step<k){
		vis[x][y]=1;
		int nx=x+dx[d],ny=y+dy[d];
		if(nx<=n&&ny<=m&&nx>=1&&ny>=1&&c[nx][ny]=='.'){
			step++;
			x=nx;
			y=ny;
		}
		else{
			step++;
			d=(d+1)%4;
		}
	}
	vis[x][y]=1;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt=0;
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)
				cin>>c[i][j];
		}
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=m;++j)
//				cout<<c[i][j];
//			cout<<endl;
//		}
		//cerr<<"ready "<<t<<endl;
		dfs(0,x,y,d);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(vis[i][j])
					cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
