#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
const ll N = 1005;
char c[N][N];
bool vis[N][N];
ll n,m,k,x,y,d,ans,xx,yy;
ll dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
bool chk(ll A,ll B){
	if(1 <= A && A <= n && 1 <= B && B <= m && c[A][B] == '.')return 1;
	return 0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y,&d);
		rep(i,1,n)rep(j,1,m)cin >> c[i][j];
		while(k--){
			xx = x + dx[d],yy = y + dy[d];
			if(chk(xx,yy)){
				if(!vis[x][y])++ans;
				vis[x][y] = 1;
				x = xx,y = yy;
			}
			else d = (d + 1) % 4;
		}
		if(!vis[x][y])++ans;
		vis[x][y] = 1;
		printf("%lld\n",ans);
		ans = 0;
	}
	return 0;
}
