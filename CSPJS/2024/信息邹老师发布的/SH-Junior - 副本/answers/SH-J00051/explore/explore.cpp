#include<bits/stdc++.h>
#define N 1005
#define M 1005
#define K 1000005
typedef long long ll;
using namespace std;
ll T,n,m,k,sx,sy,dir,ans;
bool vst[N][M];
char mp[N][M];
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
void dfs(ll x,ll y,ll d){
	if(!vst[x][y]) ans++,vst[x][y]=1;
	if(!k) return;
	ll nx=x+dx[d],ny=y+dy[d];
	if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.')	k--,dfs(nx,ny,d);
	else k--,dfs(x,y,(d+1)%4);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>sx>>sy>>dir,ans=0;
		for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) vst[i][j]=0;
		for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) cin>>mp[i][j];
		dfs(sx,sy,dir);
		cout<<ans<<endl;
	}
	return 0;
}
