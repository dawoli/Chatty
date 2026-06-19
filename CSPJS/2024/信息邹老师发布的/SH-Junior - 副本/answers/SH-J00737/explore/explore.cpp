#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
ll n,m,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char ch[N][N];
bool vst[N][N];
void solve(){
	cin>>n>>m>>k>>x>>y>>d;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			cin>>ch[i][j],vst[i][j]=0;
	vst[x][y]=1;
	for(ll i=1,nx,ny;i<=k;i++){
		nx=x+dx[d],ny=y+dy[d];
		if(nx<1||nx>n||ny<1||ny>m||ch[nx][ny]=='x') d=(d+1)%4;
		else x=nx,y=ny,vst[x][y]=1;
	}
	ll cnt=0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			cnt+=vst[i][j];
	cout<<cnt<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}
