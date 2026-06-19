#include<iostream>
#include<queue>
#define ll long long
using namespace std;
char mp[2005][2005]={"x"};
bool vis[2005][2005]={0};
bool finalflag=0;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
ll ans;
long long t,n,m,k; 
void dfs(ll sx,ll sy,ll sd,ll k){
	if(k==0){
		if(finalflag && vis[sx][sy]==0) ans++;
		return;
	}
	if(vis[sx][sy]==0){
		vis[sx][sy]=1;
		ans++;
	} 
	ll nx=sx+dx[sd];
	ll ny=sy+dy[sd];
	if(nx<=n&&ny<=m&&mp[nx][ny]=='.'){
		finalflag=1;
		dfs(nx,ny,sd,k-1);
	}
	else{
		ll tmp=(sd+1)%4;
		finalflag=0;
		dfs(sx,sy,tmp,k-1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	scanf("%ld",&t);
	queue<long long> q;
	while(t--){
		ans=0;
		scanf("%ld%ld%ld",&n,&m,&k);
		ll x0,y0,d0;
		scanf("%ld%ld%ld",&x0,&y0,&d0);
		for(ll i=1; i<=n; i++){
			for(ll j=1; j<=m; j++){
				vis[i][j]=0;
				cin>>mp[i][j];
			}
		}
		dfs(x0,y0,d0,k);
		q.push(ans);
	}
	while(q.size()){
		printf("%ld",q.front());
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
