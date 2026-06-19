#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int n,m,k,x0,y0,d0;
char a[N][N];
bool vst[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		int x=x0,y=y0,d=d0;
		for(int id=1;id<=k+1;id++){
			vst[x][y]=1;
			int vx=x+dx[d],vy=y+dy[d];
			if(vx>=1&&vx<=n&&vy>=1&&vy<=m&&a[vx][vy]=='.') x=vx,y=vy;
			else d=(d+1)%4;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vst[i][j]) cnt++;
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				vst[i][j]=0,a[i][j]='0';
	}
	return 0;
}
