#include<iostream>
#include<cstring>
using namespace std;
const int N=1e3+10;
bool map[N][N];
bool vis[N][N];
int T,n,m,k,x,y,d,cnt;
char op;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		cnt=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			cin>>op;
			if(op=='x')map[i][j]=1;
			else map[i][j]=0;
		}
		vis[x][y]=1;cnt++;
		while(k--){
			int nx=x+dir[d][0];
			int ny=y+dir[d][1];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&map[nx][ny]==0){;
				x=nx;y=ny;
				if(!vis[x][y]){
					cnt++;
					vis[x][y]=1;
				}
			}
			else d=(d+1)%4;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
