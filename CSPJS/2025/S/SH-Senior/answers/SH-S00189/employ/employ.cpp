#include <bits/stdc++.h>
#define maxn 505
#define mod 998244353
using namespace std;

int n, m, ans;
int c[maxn];
bool s[maxn], vis[maxn];
vector<int> vc;

void check() {
	int stk = 0, cnt = 0;
	if (vc.size() != n) return;
	for (int i = 0; i < n; i++) {
		if (stk >= vc[i] or !s[i]) {
			stk++;
		} else {
			cnt++;
		}
	}
	if (cnt >= m) {
		ans++;
		ans %= mod;
	}
}

void dfs(int x) {
	if (x == n) {
		check();
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			vc.push_back(c[i]);
			dfs(i + 1);
			vc.pop_back();
			vis[i] = false;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++) {
		s[i] = getchar() - '0';
	}
	getchar();
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	dfs(0);
	cout << ans;
	return 0;
}
