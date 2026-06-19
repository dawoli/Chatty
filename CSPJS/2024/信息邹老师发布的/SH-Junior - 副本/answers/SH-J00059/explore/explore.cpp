#include<bits/stdc++.h>
using namespace std;
const int N=int(1e3)+10;
long long n,m,k;
char a[N][N];
int x,y,d;
bool vis[N][N];
int dy[4]={1,0,-1,0},dx[4]={0,1,0,-1};
void dfs(int xx,int yy,int dd){
	if(k<=0)return;
	for(int i=0;i<=4;i++){
		int di=(dd+i)%4;
		if(i>=1)k--;
		if(k<=0)return;
		int x=xx+dx[di],y=yy+dy[di];
		if(x>=1&&y>=1&&x<=n&&y<=m&&a[x][y]=='.'){
			vis[x][y]=1;
			k--;
			dfs(x,y,di);
			return ;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vis[x][y]=1;
		dfs(x,y,d%4);
		int t=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1){
					t++;
				}
				vis[i][j]=0;
			}
		}
		cout<<t<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
k:4
d=2
map:....x
vis:1 0 0 0 0
x=0,y=0
di=2
k=4
x=-1,y=0
k=3
di=3
x=0,y=-1;
k=2
di=0
x=1,y=0
k=1
x=
*/
