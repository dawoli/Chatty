#include <bits/stdc++.h>
#define maxn 5005
#define mod 998244353
using namespace std;

int n;
uint64_t sum, ans, cnt;
int a[maxn];

bool check(int mx) {
	return (cnt >= 3) and (sum > mx * 2ULL);
}

void dfs(int x) {
	if (x > n) return;
	ans += check(a[x]);
	ans %= mod;
	sum += a[x + 1];
	cnt++;
	dfs(x + 1);
	cnt--;
	sum -= a[x + 1];
	dfs(x + 1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	dfs(0);
	cout << ans;
	return 0;
}
