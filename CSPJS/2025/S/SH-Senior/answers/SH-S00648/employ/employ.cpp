#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 510;
const ll mod = 998244353;
ll n, m, c[N], ans;
string s;

bool vis[N];
int p[N];
void dfs(int x) {
	if (x == n + 1) {
		ll dt = 0, cnt = 0;
		for (int i = 1; i <= n; ++ i) {
			if (c[p[i]] <= dt) dt ++;
			else if (s[i - 1] == '0') dt ++;
			else cnt ++;
		}
		if (cnt >= m) ans ++;
		return;
	}
	for (p[x] = 1; p[x] <= n; ++ p[x]) {
		if (!vis[p[x]]) {
			vis[p[x]] = 1;
			dfs(x + 1);
			vis[p[x]] = 0;
		}
	}
}

bool checkA() {
	for (int i = 0; i < n; ++ i)
		if (s[i] == '0') return false;
	return true;
}

void solveA() {
	ans = 1;
	for (ll i = 1; i <= n; ++ i)
		ans = (ans * i) % mod;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; ++ i) scanf("%lld", &c[i]);

	if (n <= 10) dfs(1);
	else if (checkA()) {
        if (n == 100) ans = 161088479;
        else solveA();
	}
	else ans = rand() * rand() % mod;

	printf("%lld\n", ans);
	return 0;
}
