#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int T,n,m,k;
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
char a[N][N];bool vis[N][N];
bool is(int x,int y) {
	if(x<1||x>n||y<1||y>m||a[x][y]=='x')
		return 0;
	else return 1;
}
void dfs(int x,int y,int d,int cnt) {
	if(cnt>k)	return;
	vis[x][y]=1;
	if(is(x+dx[d],y+dy[d])) dfs(x+dx[d],y+dy[d],d,cnt+1);
	else {
		int c=0;
		do {
			d=(d+1)%4;c++;
			if(c+cnt+1>k) return;
		} while(!is(x+dx[d],y+dy[d]));
		dfs(x+dx[d],y+dy[d],d,cnt+c+1);
	}
}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				cin>>a[i][j];
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				vis[i][j]=0;
		dfs(x,y,d,0);int cnt=0;
		for(int i=1; i<=n; i++){ 
			for(int j=1; j<=m; j++)
				if(vis[i][j]==1) cnt++;
		} 
		cout<<cnt<<"\n";
	}
	return 0;
}
