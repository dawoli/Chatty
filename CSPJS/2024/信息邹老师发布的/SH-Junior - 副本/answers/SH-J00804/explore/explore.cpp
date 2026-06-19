#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
using namespace std;
const int N=1e3+5;
int n,m,k,x,y,d;
int dx[5]={0,1,0,-1,0},dy[5]={1,0,-1,0,0};
bool mp[N][N],vis[N][N];
string s;
void init(){
	memset(mp,false,sizeof(mp));
	memset(vis,false,sizeof(vis));
	return;
}
bool check(int x,int y){
	if(x>0&&y>0&&x<=n&&y<=m){
		if(mp[x][y])return true;
		else return false;
	}
	return false;
}
void solve(){
	init();
	cin>>n>>m>>k>>x>>y>>d;
	rep(i,1,n){
		cin>>s;
		rep(j,0,m-1)
			if(s[j]=='.')
				mp[i][j+1]=true;
	}
	vis[x][y]=true;
	ll ans=1;
	rep(i,1,k){
		int tx=x+dx[d],ty=y+dy[d];
		if(check(tx,ty)){
			x=tx;
			y=ty;
		}
		else d=(d+1)%4;
		if(!vis[x][y]){
			ans++;
			vis[x][y]=true;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	int TEST;
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>TEST;
	while(TEST--)
		solve();
	return 0;
}
