#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int mod = 998244353;
int n, m, ans, c[MAXN];
bool hard[MAXN], vis[MAXN];
string s;
vector <int> v;

int MOD(int x){
	return ((x % mod) + mod) % mod;
}

void dfs(int now, int tot){
	int d = now - 1 - tot;
	int cnt = 0;
	for (int i = 1; i <= n; ++i){
		if (!vis[i]){
			if (d < c[i])
				++cnt;
		}
	}
	if (cnt + tot < m)
		return;
	if (now == n + 1){
		if (tot >= m){
			++ans;
			MOD(ans);
		}
		return;
	}
	for (int i = 1; i <= n; ++i){
		if (!vis[i]){
			vis[i] = true;
			if (hard[now] && d < c[i])
				dfs(now + 1, tot + 1);
			else
				dfs(now + 1, tot);
			vis[i] = false;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.length(); ++i)
		hard[i + 1] = s[i] - '0';
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	dfs(1, 0);
	cout << ans;
	return 0; 
}
