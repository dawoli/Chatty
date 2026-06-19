#include<bits/stdc++.h>
#define y0 wodjweif
using namespace std;

const int N=1e3+10;
int n,m,k;
int x0,y0,d0;
int T;
int a[N][N];
bool vis[N][N];int ans;
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};

void dfs(){
	int x=x0,y=y0,d=d0;
	if(!vis[x][y]){
			vis[x][y]=1; ans++;
		}
	while(k--){
		
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(!a[nx][ny]&&nx>=1&&nx<=n&&ny>=1&&ny<=m){
			x=nx; y=ny;
			if(!vis[nx][ny]){
			vis[nx][ny]=1; ans++;
			}
		}
		else{
			d=(d+1)%4;
		}
	}
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m>>k;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=m;j++){
		    	char ch;
		    	cin>>ch;
		    	if(ch=='x') a[i][j]=1;
			}
		}
		dfs();
		cout<<ans<<"\n";
	}
	
	return 0;
}
