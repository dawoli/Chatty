#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int t;
int n,m,k,x,y,d;
char g[N][N];
bool flag[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		memset(flag,0,sizeof(flag));
		memset(g,' ',sizeof(g));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) cin>>g[i][j];
		flag[x][y]=1;
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&g[nx][ny]=='.')
				x=nx,y=ny,flag[x][y]=true;
			else
				d=(d+1)%4;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(flag[i][j]) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
