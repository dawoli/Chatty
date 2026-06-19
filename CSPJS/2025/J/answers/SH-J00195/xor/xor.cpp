#include <bits/stdc++.h>
#define maxn 500005
using namespace std;

int n, k;
int64_t ans;
int a[maxn];
bool vis[maxn];
vector<int> now;

bool check() {
	if (now.size() == 0) {
		return false;
	}
	int xr = 0;
	for (int i : now) {
		if (vis[i]) {
			return false;
		}
		xr ^= a[i];
	}
	if (xr == k) {
		for (int i : now) {
			vis[i] = true;
		}
	}
	return xr == k;
}

void dfs(int x) {
	ans += check();
	for (int i = x + 1; i <= n; i++) {
		if (!vis[i]) {
			now.push_back(i);
			dfs(i);
			now.pop_back();
		}
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0);
	cout << ans;
	return 0;
}
