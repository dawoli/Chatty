#include <bits/stdc++.h>
using namespace std;

int T,n,m,k,ans;
char g[1005][1005];
bool vis[1005][1005];
int d[5][3]={{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int stx,int sty,int std){
	if(vis[stx][sty]==0) ans++;
	vis[stx][sty]=1;
	if(k<=0) return;
	int nx=d[std][0]+stx;
	int ny=d[std][1]+sty;
	if(nx<1 || nx>n || ny<1 || ny>m || g[nx][ny]=='x'){
		k--;
		dfs(stx,sty,(std+1)%4);
	}else{
		k--;
		dfs(nx,ny,std);
	}
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int aa=1;aa<=T;aa++){
		ans=0;
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		int stx,sty,std;
		cin>>stx>>sty>>std;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>g[i][j];
			}
		}
		dfs(stx,sty,std);
		cout<<ans<<endl;
	}
	return 0;
}
