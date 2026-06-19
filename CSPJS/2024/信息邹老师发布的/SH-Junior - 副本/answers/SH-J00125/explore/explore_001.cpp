#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d,nx,ny;
int cnt = 1;
char mp[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i = 1;i<=t;i++){
		cnt = 1;
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=m;k++){
				cin>>mp[j][k];
			}
		}
		for(int j = 1;j<=k;j++){
			if(d==0){
				nx=x;
				ny=y+1;
			}
			else if(d==1){
				nx=x+1;
				ny=y;
			}
			else if(d==2){
				nx=x;
				ny=y-1;
			}
			else if(d==3){
				nx=x-1;
				ny=y;
			}
			if(nx<1||ny<1||nx>n||ny>m||mp[nx][ny]=='x'){
				d=(d+1)%4;
			}
			else if(vis[nx][ny]){
				x=nx;
				y=ny;
			}
			else{
				vis[nx][ny]=1;
				cnt++;
				x=nx;
				y=ny;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
