#include<bits/stdc++.h>
using namespace std;
const int N=1002,M=1002;
int n,m;
char a[N][M];
bool b[N][M];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool bj(int x,int y){return x>=1 && x<=n && y>=1 && y<=m && a[x][y]=='.';}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int q,x,y,d;
		cin>>n>>m>>q>>x>>y>>d;
		for(int i=1;i<=n;i++) cin>>a[i]+1;
		b[x][y]=1;
		while(q--){
			int nx=x+dir[d][0];
			int ny=y+dir[d][1];
			if(bj(nx,ny)){
				x=nx,y=ny;
				b[nx][ny]=1;
			}
			else d=(d+1)%4;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j]) ans++;
				b[i][j]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
