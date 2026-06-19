#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,d,sx,sy,ans;
char a[1005][1005];
bool f[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int h=1;h<=T;h++){
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				f[i][j]=false;
			}
		}
		f[sx][sy]=true;
		for(int i=1;i<=k;i++){
			int nx=sx+dx[d];
			int ny=sy+dy[d];
			if(nx<1 or nx>n or ny<1 or ny>m or a[nx][ny]=='x'){
				d=(d+1)%4; 
				continue;
			}
			f[nx][ny]=true;
			sx=nx,sy=ny;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(f[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
