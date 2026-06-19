#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll n,m,k;
char mp[1009][1009];
bool vst[1009][1009];
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
void solve(){
	scanf("%lld%lld%lld",&n,&m,&k);
	ll x,y,d;
	scanf("%lld%lld%lld",&x,&y,&d);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++){
			cin>>mp[i][j];
			vst[i][j]=0;
		}
	ll ans=1;
	vst[x][y]=1;
	for(ll i=1;i<=k;i++){
		ll nx=x+dx[d],ny=y+dy[d];
		if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]!='.') d=(d+1)%4;
		else{
			if(vst[nx][ny]==0) ans++;
			vst[nx][ny]=1;
			x=nx,y=ny;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
}
