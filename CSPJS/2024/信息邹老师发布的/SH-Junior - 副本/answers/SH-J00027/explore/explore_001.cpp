#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int T,n,m,k,x,y,d;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char c[N][N];
bool vst[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) cin>>c[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) vst[i][j]=0;
		vst[x][y]=1;
		for(int u=1;u<=k;u++){
			int xn=x+dx[d],yn=y+dy[d];
			if(x>=1&&x<=n&&y>=1&&y<=m&&c[xn][yn]=='.'){
				x=xn,y=yn; vst[xn][yn]=1;
			}else d=(d+1)%4;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) if(vst[i][j]==1) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}

