#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 501, mod = 998244353;
ll n, m, sum[N], st[N], c[N], ans;
char s[N];
bool ss[N], vst[N];
bool dfs(ll x){
	if (x == n + 1){
		ll cnt = 0, get = 0;
		for (ll i = 1;i <= n;i++){
			if (cnt < c[st[i]] && ss[i]){
				get++;
			}else{
				cnt++;
			}
		}
		if (get >= m){
			ans = (ans + 1) % mod;
		}
	}
	for (ll i = 1;i <= n;i++){
		if (vst[i]){
			continue;
		}
		vst[i] = 1;
		st[x] = i;
		dfs(x + 1);
		st[x] = 0;
		vst[i] = 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (ll i = 0;i < n;i++){
		ss[i + 1] = bool(s[i] - '0');
		sum[i + 1] = sum[i] + ss[i + 1];
	}
	if (sum[n] < m){
		cout << "0" << "\n";
		return 0;
	}
	for (ll i = 1;i <= n;i++){
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	if (m == n){
		ans = 1;
		for (ll i = 1;i <= n;i++){
			ans = ans * (c[i] - i + 1) % mod;
		}
	}else{
		dfs(1);
	}
	cout << ans;
	return 0;
}
