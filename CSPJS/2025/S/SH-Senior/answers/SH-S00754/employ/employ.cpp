// CSP RP += 0x3f3f3f3f3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353, N = 500;
int n, m, c[N + 5], p[N + 5];
bitset<N + 5> us;
string s;
ll ans;

void dfs(int u){
	if(u > n){
		int nc = 0, o = 1;
		for(int i = 1; i <= n; ++ i){
			if(nc >= c[p[i]]){
				++ nc;
				continue;
			}
			else if(s[o ++] == '0') ++ nc;
		}
		if(nc <= n - m) (++ ans) %= MOD;
	}
	else for(int i = 1; i <= n; ++ i) if(!us[i]){
		us.set(i);
		p[u] = i;
		dfs(u + 1);
		us.reset(i);
	}
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> s;
	s = " " + s;
	for(int i = 1; i <= n; ++ i) cin >> c[i];
	dfs(1);
	cout << ans;
}

