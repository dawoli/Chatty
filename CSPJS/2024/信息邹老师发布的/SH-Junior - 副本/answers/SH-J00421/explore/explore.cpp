#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+10;
char a[N][N];
ll t,dx[4]= {0,1,0,-1},dy[4]= {1,0,-1,0};
bool vis[N][N];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		ll n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(ll i=1; i<=n; ++i)
			for(ll j=1; j<=m; ++j) cin>>a[i][j];
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		while(k--) {
			ll nx=x+dx[d],ny=y+dy[d];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]=='.') {
				if(!vis[nx][ny]) ++ans;
				vis[nx][ny]=1,x=nx,y=ny;
			} else d=(d+1)%4;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
