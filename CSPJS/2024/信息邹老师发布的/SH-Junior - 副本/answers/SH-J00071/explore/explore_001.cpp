#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,xx[4]={0,1,0,-1},yy[4]={1,0,-1,0},ans;
char a[110][110];
int vis[110][110];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;++j){
			for(int l=1;l<=m;++l){
				cin>>a[j][l];
			}
		}
		memset(vis,0,sizeof(vis));
		ans=0;
		vis[x][y]=1;
		for(int j=1;j<=k;++j){
			int nx=xx[d]+x;
			int ny=yy[d]+y;
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'){
				x=nx,y=ny;
				vis[x][y]=1;
			}else{
				d=(d+1)%4;
			}
		}
		for(int j=1;j<=n;++j){
			for(int l=1;l<=m;++l){
				if(vis[j][l]){
					++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
