#include<bits/stdc++.h>
using namespace std;
#define N 1007
int mp[N][N];
int vis[N][N];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m,k,sx,sy,sd;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k>>sx>>sy>>sd;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				char s;
				cin>>s;
				mp[i][j]=(s=='.');
			}
		}
		int x=sx,y=sy,d=sd;
		vis[x][y]=1;
		while(k--){
			int xx=x+dx[d],yy=y+dy[d];
			//cout<<xx<<' '<<yy<<' '<<mp[xx][yy]<<'\n';
			if(xx<1||xx>n||yy<1||yy>m||!mp[xx][yy]){
				d=(d+1)%4;
			}
			else{
				//cout<<xx<<' '<<yy<<'\n';
				vis[xx][yy]=1;
				x=xx,y=yy;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				ans+=vis[i][j];
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
 
