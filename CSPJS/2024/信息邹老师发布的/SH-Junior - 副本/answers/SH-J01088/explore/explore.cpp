#include<bits/stdc++.h>
using namespace std;
int T,n,m,kk,xx,yy,dd,ans=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool mp[1009][1009],vis[1009][1009];
char ch;
void wrk(int x,int y,int dir,int k){
	if(k==0){
		return;
	}
	int nx=x+dx[dir],ny=y+dy[dir];
	if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]==1){
		dir=(dir+1)%4;
		wrk(x,y,dir,k-1);
	}else{
		if(!vis[nx][ny]){
			ans++;
			vis[nx][ny]=1;
		}
		wrk(nx,ny,dir,k-1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>kk;
		cin>>xx>>yy>>dd;
		ans=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=0;
				cin>>ch;
				if(ch=='x'){
					mp[i][j]=1;
				}else{
					mp[i][j]=0;
				}
			}
		}
		vis[xx][yy]=1;
		wrk(xx,yy,dd,kk);
		cout<<ans<<endl;
	}
	return 0;
}
