#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;

struct node {
	int a, b, c;
} a[100010];

void dfs(int now, int x, int y, int z, int sum) {
	if (now > n) {
		ans = max(ans, sum);
		return;
	}
	if (x < n / 2) dfs(now +1, x + 1, y, z, sum + a[now].a);
	if (y < n / 2) dfs(now +1, x, y + 1, z, sum + a[now].b);
	if (z < n / 2) dfs(now +1, x, y, z + 1, sum + a[now].c);
}

bool cmp(node x, node y) {
	if (x.a != y.a) return x.a >y.a;
	if (x.b != y.b) return x.b > y.b;
	return x.c >y.c;
}

void solve() {
	cin >> n;
	bool b = 1, c = 1;
	for (int i = 1; i <= n; i++) {
		cin >>a[i].a >>a[i].b >>a[i].c; 
		if (a[i].b != 0) b = 0;
		if (a[i].c != 0) c = 0;
	}
	if (n <= 30) {
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		cout <<ans <<"\n";
		return ;
	}
	sort(a +1, a + n +1, cmp);
	if (b && c) {
		for (int i = 1; i <= n / 2; i++) {
			ans += a[i].a;
		}
		cout <<ans <<"\n";
		return;
	}
	if (c) {
		int sum = 0;
		int bb = 0, cc = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].a > a[i].b && bb < n / 2) sum += a[i].a, bb++;
			else if (a[i].b >a[i].a && cc < n/2) sum += a[i].b, cc++;
			else if (bb <n /2) sum += a[i].a, bb++;
			else if (cc <n / 2) sum += a[i].b, cc++; 
		}
		cout << sum <<"\n";
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >>t;
	while (t--) solve();
	return 0;
}
