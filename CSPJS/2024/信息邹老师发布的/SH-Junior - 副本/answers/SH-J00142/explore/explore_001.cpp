#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int vis[N][N],T,n,m,k,X0,Y0,d0,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char a[N][N];
int main(){
	freopen("explore.in","r",stdin),freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>X0>>Y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j],vis[i][j]=0;
			}
		}
		int ans=1;
		vis[X0][Y0]=1;
		while(k--){
			int nx=X0+dx[d0],ny=Y0+dy[d0];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'){
				X0=nx,Y0=ny;
				if(!vis[X0][Y0]){
					ans++,vis[X0][Y0]=1;
				}
			}
			else{
				d0=(d0+1)%4;
			}
		}
		cout<<ans<<'\n';
	}
}
