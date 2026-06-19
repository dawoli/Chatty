#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 510;
const int mod = 998244353;
int n, m, c[maxn], succ[maxn];
ll ans = 0;
char s[maxn];
vector <int> G[maxn];
bool vis[maxn];
ll jiechen(int x) {
	ll ans0 = 1;
	if (x == 0 || x == 1) return 1;
	for (int i = x; i >= 1; i--) {
		ans0 *= i;
		ans0 %= mod;
	}
	return ans0;
}

void dfs(int x, ll an, int num) {
	if (x == n + 1 && num >= m) {
		ans += 1;
		ans %= mod;
		return;
	}
	if (s[x] == '1') {
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) {
				int st = 1;
				vis[i] = 1;
				for (int j = 0; j < G[x].size(); j++) {
					if (i == G[x][j]) {
						dfs(x + 1, an, num + 1);
						st = 0;
						break;
					}
				}
				if (st) dfs(x + 1, an, num);
				vis[i] = 0;
			}
		}
	}
	else if (s[x] == '0') {
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) {
				vis[i] = 1;
				dfs(x + 1, an, num);
				vis[i] = 0;
			}
		}
	}
	return;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	cin >> (s + 1);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	
	int cnt = 0, state = 1;
	for (int i = 1; i <= n - 1; i++) {
		if (s[i] == '0') {
			state = 0;
			succ[i+1] = succ[i] + 1;
		}
		else {
			cnt++;
			succ[i+1] = succ[i];
		}
	}
	if (s[n] == '0') {
		state = 0;
	} else {
		cnt++;
	}
	
	
	if (cnt < m) {
		cout << '0' << '\n';
		return 0;
	}
	if (state == 1) {
		cout << jiechen(n) << '\n';
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			for (int j = 1; j <= n; j++) {
				if (succ[i] < c[j]) {
					G[i].push_back(j);
				}
			}
		}
	}
	dfs(1,1,0);
	
	cout << ans << '\n';
	return 0;
}
