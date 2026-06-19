#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const ll maxn=1e3+9;
const ll dx[]={0,1, 0,-1};
const ll dy[]={1,0,-1, 0};
ll n,m,k,sx,sy,sd;
bool b[maxn][maxn],vst[maxn][maxn];
void mymain(){
	cin>>n>>m>>k>>sx>>sy>>sd;
	rep(i,0,n+1)	rep(j,0,m+1)	b[i][j]=1;
	rep(i,1,n)	rep(j,1,m){
		char ch;
		cin>>ch;
		b[i][j]=(ch=='x');
	}
	ll x=sx,y=sy,d=sd;
	rep(i,1,n)	rep(j,1,m)	vst[i][j]=0;
	vst[x][y]=1;
	while(k-->0){
		ll nx=x+dx[d],ny=y+dy[d];
		if(b[nx][ny]||nx<1||nx>n||ny<1||ny>m){
			d=(d+1)%4;
		}
		else{
			x=nx,y=ny;
		}
		vst[x][y]=1;
	}
	ll ans=0;
//	rep(i,1,n)	rep(j,1,m)	cout<<vst[i][j]<<(j==m?'\n':' ');
	rep(i,1,n)	rep(j,1,m)	if(vst[i][j])	ans++;
	cout<<ans<<'\n';
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll T;
	cin>>T;
	while(T-->0){mymain();}
	return 0;
} 
