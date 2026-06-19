#include <bits/stdc++.h>
using namespace std;
int n, t, a[200010], pre[200010], mem[110][110][110], cache[110][110][110];
int l[3];
int c[200010], ans;
int dfs(int x, int la, int lb) {
	if (x > n) {
		return 0;
	}
	if (mem[x][la][lb]) return cache[x][la][lb];
	mem[x][la][lb] = 1;
	int ansa = dfs(x + 1, x, lb) + (a[la] == a[x] ? a[x] : 0);
	int ansb = dfs(x + 1, la, x) + (a[lb] == a[x] ? a[x] : 0);
	return cache[x][la][lb] = max(ansa, ansb);
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout); 
	cin >> t;
	while (t--) {
		memset(mem, 0, sizeof(mem));
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		} 
		cout << dfs(1, 0, 0) << endl;
	}
	return 0;
}
