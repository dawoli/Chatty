#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll t,n,ans,g[4],a[N][3];
struct node {
	ll b[3],d,sum;
} f[N][3];
void input() {
	cin>>n;
	for(ll i = 1;i <= n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
}
void dfs(ll pos,ll flag,ll sum) {
	if(g[1] > n / 2 || g[2] > n / 2 || g[3] > n / 2) return;
	if(pos == n + 1) {
		ans = max(ans,sum); return;
	}
	g[1] += 1;
	dfs(pos + 1,1,sum + a[pos][0]);
	g[1] -= 1; g[2] += 1;
	dfs(pos + 1,2,sum + a[pos][1]);
	g[2] -= 1; g[3] += 1;
	dfs(pos + 1,3,sum + a[pos][2]);
	g[3] -= 1;
}
void solve1() {
	ans = 0; dfs(1,0,0); cout<<ans<<'\n';
}
void solve() {
	for(ll i = 1;i <= n;i++) {
		for(ll j = 0;j < 3;j++) f[i][j] = {{0,0,0},0};
	}
	for(ll i = 1;i <= n;i++) {
		for(ll j = 0;j < 3;j++) {
			for(ll k = 0;k < 3;k++) {
				if((f[i][j].d < f[i - 1][k].d + a[i][j] || (f[i][j].d == f[i - 1][k].d + a[i][j] && f[i][j].sum > f[i - 1][k].sum + 1)) && f[i - 1][k].b[j] + 1 <= n / 2) {
					f[i][j] = {{f[i - 1][k].b[0],f[i - 1][k].b[1],f[i - 1][k].b[2]},f[i - 1][k].d + a[i][j],f[i - 1][k].b[0] + f[i - 1][k].b[1] + f[i - 1][k].b[2]}; f[i][j].b[j] += 1; 
//					cout<<i<<" "<<j<<" "<<f[i][j].d<<" "<<f[i][j].b[j]<<'\n';
				} 
			}
		}
	}
	cout<<max(f[n][0].d,max(f[n][1].d,f[n][2].d))<<'\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--) {
		input();
		if(n <= 10) solve1();
		else solve();
	}
	return 0;
} 
