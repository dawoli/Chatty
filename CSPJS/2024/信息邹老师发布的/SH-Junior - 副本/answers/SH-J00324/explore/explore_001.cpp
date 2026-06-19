#include<bits/stdc++.h>
#define N 1001
using namespace std;
typedef long long ll;
ll n,m,k,xS,yS,dS;
string s[N];
bool vst[N][N];
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
bool ok(ll x,ll y){
	if(x<1||x>n||y<1||y>m) return 0;
	if(s[x][y]=='x') return 0;
	return 1;
}
void input(){
	cin>>n>>m>>k;
	cin>>xS>>yS>>dS;
	for(ll i=1;i<=n;i++) cin>>s[i];
}
void solve(){
	for(ll i=1;i<=n;i++) s[i]=" "+s[i];
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++) vst[i][j]=0;
	ll x=xS,y=yS,d=dS,cnt=1;
	vst[x][y]=1;
	for(ll t=1;t<=k;t++){
		ll nx=x+dx[d],ny=y+dy[d];
		if(ok(nx,ny)){
			x=nx;
			y=ny;
		}else d=(d+1)%4;
		if(!vst[x][y]){
			cnt++;
			vst[x][y]=1;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll T;
	cin>>T;
	for(ll i=1;i<=T;i++){
		input();
		solve();
	}
	return 0;
}

