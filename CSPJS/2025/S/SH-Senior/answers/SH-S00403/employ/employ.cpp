#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500 + 9;
const ll MOD = 998244353; 
#define re(i, n) for(ll i = 1; i <= n; i++)
#define rr(i, l, r) for(ll i = l; i <= r; i++)
#define pb push_back
ll n, m;
char s[N];
ll c[N];
bool vis[N];
ll ans = 0;
void dfs(ll u, ll cur) {
	if(u == n + 1) {
		if(n - cur >= m) ans++;
		return ;
	}
	if(u - 1 - cur >= m) {
		ll delta = 1; 
		rr(i, u, n) delta = (delta * (i - u + 1)) % MOD;
		ans = (ans + delta) % MOD;
		return ;
	}
	if(n - cur < m) return ;
	re(i, n) {
		if(vis[i]) continue;
		vis[i] = 1;
		if(cur < c[i] && s[u] == '1') 
			dfs(u + 1, cur);
		else 
			dfs(u + 1, cur + 1); 
		vis[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	re(i, n) cin>>s[i];
	re(i, n) cin>>c[i];
	if(n <= 10) { 
		dfs(1, 0);
		cout<<ans<<endl;
	} else if(m == n) {
		ll flag = 1;
		re(i, n) {
			if(s[i] == '0')
				flag = 0;
		}
		if(flag) cout<<0<<endl;
		else {
			ll ans = 1;
			re(i, n) ans = (ans * i) % MOD;
			cout<<ans<<endl;
		}
	} else if(m == 1) {
		ll ans = 0;
		re(i, n) {
			if(s[i] == '0') continue;
			ll mul = 1;
			rr(j, i + 1, n) 
				mul = (mul * (j - i)) % MOD;
			re(j, n) {
				if(c[j] < i - 1)
					ans = (ans + mul) % MOD;
			}
		} cout<<ans<<endl;
	} else {
		dfs(1, 0);
		cout<<ans<<endl;
	}
	return 0;
}

