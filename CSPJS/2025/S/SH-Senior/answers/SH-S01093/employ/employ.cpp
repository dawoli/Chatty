#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m, c[505], a[505], d[20], ans = 0;
bool vis[20];
int check(){
	int w = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] == 0){
			w++;
		}
		else if (w >= c[d[i]]){
			w++;
		}
	}
	return (n - w) >= m;
}
void dfs(int dep){
	if (dep == n + 1){
		ans += check();
		ans %= mod;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i]){
			continue;
		}
		vis[i] = 1;
		d[dep] = i;
		dfs(dep + 1);
		vis[i] = 0;
		d[dep] = 0;
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int flag = 1;
	for (int i = 1; i <= n; i++){
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}

