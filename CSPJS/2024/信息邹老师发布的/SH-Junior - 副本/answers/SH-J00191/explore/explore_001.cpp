#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,cnt;
bool book[1110][1110];
char a[1110][1110];
int dir[2][4]={
	0,1,0,-1,
	1,0,-1,0
};
bool bj(int x,int y){
	if( x>=1 && x<=n && y>=1 && y<=m) return 1;
	return 0;
}
void dfs(int x,int y,int d,int s){
	if(s==0){
		return;
	}
	int nx=x+dir[0][d];
	int ny=y+dir[1][d];
	if(bj(nx,ny) && a[nx][ny]=='.'){
		if(book[nx][ny]==0){
			book[nx][ny]=1;
			cnt++;
		}
		dfs(nx,ny,d,s-1);
		book[nx][ny]=0;
	}
	else dfs(x,y,(d+1)%4,s-1);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		cnt=1;
		book[x][y]=1;
		dfs(x,y,d,k);
		book[x][y]=0;
		cout<<cnt<<"\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=0;
			}
		}
	}
	return 0;
}
