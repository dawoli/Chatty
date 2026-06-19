#include<bits/stdc++.h>
using namespace std;
const int N=1015;
int dx[6]={0,1,0,-1};
int dy[6]={1,0,-1,0};
char a[N][N];
int n,m,k;
int X,Y,D;
bool st[N][N];
void dfs(int x,int y,int d,int dep){
	if(dep>k)return;
	if(x<1||x>n||y<1||y>m||a[x][y]=='x')return;
	st[x][y]=1;
	int xx=x+dx[d],yy=y+dy[d];
	if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]=='x'){
		d=(d+1)%4;
		xx=x,yy=y;
	}
	dfs(xx,yy,d,dep+1);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(st,0,sizeof st);
		cin>>n>>m>>k>>X>>Y>>D;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(X,Y,D,0);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(st[i][j]==1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
