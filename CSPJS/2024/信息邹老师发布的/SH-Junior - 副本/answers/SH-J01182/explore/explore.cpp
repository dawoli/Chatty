#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int T,n,m,k,vst[N][N];
char c[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int p=1;p<=T;p++){
		int n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<N;i++) for(int j=1;j<N;j++) vst[i][j]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>c[i][j];
		vst[x][y]=1;
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<=n&&nx>0&&ny<=m&&ny>0&&c[nx][ny]!='x'){
				x=nx,y=ny;
				if(vst[nx][ny]) continue;
				vst[x][y]=1;
				ans++;
			}
			else d=(d+1)%4;
		}
		cout<<ans<<endl;
	}
	return 0;
}

