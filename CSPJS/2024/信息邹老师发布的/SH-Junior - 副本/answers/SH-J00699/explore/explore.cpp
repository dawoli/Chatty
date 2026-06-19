#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Rset(x) Set(x,0)
#define cll const long long
using namespace std;
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
cll N=1009;
ll n,m,k,x,y,d; char c[N][N]; bool vst[N][N]; 
bool valid(ll a,ll b){
	if(a<1||b<1||a>n||b>m)return 0;
	if(c[a][b]=='x')return 0;
	return 1;
}
void input(){
	cin>>n>>m>>k>>x>>y>>d;
	rep(i,1,n)rep(j,1,m)cin>>c[i][j],vst[i][j]=0;
}
void solve(){
	vst[x][y]=1;
	rep(i,1,k){
		ll nx=x+dx[d],ny=y+dy[d];
		if(valid(nx,ny))x=nx,y=ny,vst[nx][ny]=1;
		else d=(d+1)%4;
	}
	ll ans=0;
	rep(i,1,n)rep(j,1,m)ans+=vst[i][j];
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll t;cin>>t;
	while(t--){
		input();
		solve();
	} 
	return 0;
}

