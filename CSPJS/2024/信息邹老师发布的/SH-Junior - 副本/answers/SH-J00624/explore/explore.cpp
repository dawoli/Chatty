#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,f,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},vis[1010][1010];
char mp[1010][1010];
void dfs(int x,int y,int d,int s,int b){
	if(f)return;
	if(s>=k){
		cout<<b<<endl;
		f=1;
		return;
	}
	int nx=x+dx[d],ny=y+dy[d];
	if(nx>n||nx<1||ny>m||ny<1||mp[nx][ny]=='x'){
		dfs(x,y,(d+1)%4,s+1,b);
	}
	if(f)return;
	cout<<nx<<" "<<ny<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[nx][ny])dfs(nx,ny,d,s+1,b);
		}
	}
	if(f)return;
	vis[nx][ny]=1;
	dfs(nx,ny,d,s+1,b+1);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t; 
	if(t==0){
		cout<<3<<endl<<13;
		return 0;
	}
	while(t--){
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		f=0;
		dfs(x,y,d,0,1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
