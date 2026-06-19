#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n, m, s[505], c[505], ans;
bool ta = true, vis[505];

void dfs(int step, int ts, int ls){
	if (step >= n){
		if (ls >= m) ans ++;
		ans %= MOD;
		return;
	}
	for (int i = 1; i <= n; i ++){
		if (!vis[i]){
			vis[i] = true;
			if (ts >= c[i] || s[step+1] == 0) dfs(step+1, ts+1, ls);
			else if (s[step+1] == 1) dfs(step+1, ts, ls+1);
			vis[i] = false;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		char t;
		cin >> t;
		s[i] = t-'0';
		if (s[i] != 1) ta = false;
	}
	for (int i = 1; i <= n; i ++){
		cin >> c[n];
	}
	if (ta){//n!
		ans = 1;
		for (int i = n; i >= 1; i --){
			ans *= i;
			ans %= MOD;
		}
		cout << ans;
		return 0;
	}
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i ++){
		vis[i] = true;
		if (s[1] == 0 || c[i] != 0) dfs(1, 1, 0);
		else dfs(1, 0, 1);
		vis[i] = false;
	}
	cout << ans;
	return 0;
} 
