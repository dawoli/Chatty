#include<bits/stdc++.h>
using namespace std;
char ch[1005][1005];
int n,m,minb=INT_MAX,d=INT_MAX;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[1005][1005];
void dfs(int x,int y,int num,int dis){
	if(x==n && y==m){
		if(minb>num){
			minb=num;
			d=dis;
		}
		else if(minb==num){
			d=min(d,dis);
		}
		return;
	}
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(ch[nx][ny]!='*' && !vis[nx][ny] && nx>=1 && nx<=n && ny>=1 && ny<=m){
			vis[nx][ny]=1;
			dis++;
			if(ch[nx][ny]=='$') num++;
			dfs(nx,ny,num,dis);
			vis[nx][ny]=0;
			if(ch[nx][ny]=='$') num--;
			dis--;
		}
	}
}
void solve(){
	minb=INT_MAX,d=INT_MAX;
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch[i][j];
		}
	}
	dfs(1,1,0,0);
	cout<<minb<<" "<<d<<endl;
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
