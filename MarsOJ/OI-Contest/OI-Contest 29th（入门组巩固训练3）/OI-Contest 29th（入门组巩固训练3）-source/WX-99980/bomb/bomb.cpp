#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
bool vis[1005][1005];
int go[4][2]={0,1,1,0,0,-1,-1,0};
char mp[1005][1005];
struct tans{
	int bao,zho;
};
tans dfs(int x,int y,tans cnt){
	vis[x][y]=1;
	tans min={0x3f3f3f,0x3f3f3f};
	for(int i=0;i<4;i++){
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		tans ncnt={cnt.bao,cnt.zho+1};
		if(nx<1 || nx>n || ny<1 || ny>m)continue;
		if(mp[nx][ny]=='*')continue;
		if(mp[nx][ny]=='$')ncnt.zho++,ncnt.bao++;
		if(vis[nx][ny])continue;
		tans next=dfs(nx,ny,ncnt);
		if(next.bao<min.bao){
			min.bao=next.bao,min.zho=next.zho;
		}
	}
	if(min.bao==0x3f3f3f && min.zho==0x3f3f3f)min=cnt;
	//cout<<x<<" "<<y<<" "<<min.bao<<" "<<min.zho<<endl;
	vis[x][y]=0;
	return min;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	memset(vis,0,sizeof(vis));
	tans ans=dfs(1,1,{0,0});
	cout<<ans.bao<<" "<<ans.zho<<endl;
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
}
