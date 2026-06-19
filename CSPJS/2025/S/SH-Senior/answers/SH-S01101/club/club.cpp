#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <random>
using namespace std;

int T, n, a[100005][5], b[100005], ans;

void dfs(int step, int sum, int cnt1, int cnt2, int cnt3) {
	if (step > n) {
		ans = max(ans, sum);
		return ;
	}
	if (cnt1 < n/2) {
		dfs(step+1, sum+a[step][1], cnt1+1, cnt2, cnt3);
	}
	if (cnt2 < n/2) {
		dfs(step+1, sum+a[step][2], cnt1, cnt2+1, cnt3);
	}
	if (cnt3 < n/2) {
		dfs(step+1, sum+a[step][3], cnt1, cnt2, cnt3+1);
	}
}
void solve1() {
	ans = 0;
	dfs(1, 0, 0, 0, 0);
	printf("%d\n", ans);
}
int f[205][105][105];
void solve2() {
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(i, n/2); j++)
			for (int k = 0; k <= min(i-j, n/2); k++) {
				if (j > 0) f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k] + a[i][1]);
				if (k > 0) f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1] + a[i][2]);
				if (j+k<i&&i-j-k<=n/2) f[i][j][k] = max(f[i][j][k], f[i-1][j][k] + a[i][3]);
			}
	}
	int ans = 0;
	for (int j = 0; j <= n/2; j++)
		for (int k = 0; k <= n/2; k++)
			ans = max(ans, f[n][j][k]);
	printf("%d\n", ans);
}

bool isA() {
	for (int i = 1; i <= n; i++)
		if (a[i][2] || a[i][3]) return false;
	return true;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; _++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				scanf("%d", &a[i][j]);
		if (n <= 10) { solve1(); continue; }
		if (n <= 200) { solve2(); continue; }
		if (isA()) {
			int ans = 0;
			for (int i = 1; i <= n; i++)
				b[i] = a[i][1];
			sort(b+1, b+n+1);
			for (int i = n; i > n/2; i--)
				ans += b[i];
			printf("%d\n", ans);
			continue;
		}
		mt19937 gen(time(0));
		uniform_int_distribution<> A(1, n), B(0, n/2);
		int cnt = 1e8 / T / n;
		int ans = 0;
		while (cnt--) {
			int x = A(gen), y = B(gen);
			swap(x, y);
			int o = B(gen), p = B(gen);
			int cnt = 0;
			for (int i = 1; i <= o; i++)
				cnt += a[i][1];
			for (int i = o+1; i <= o+p; i++)
				cnt += a[i][2];
			for (int i = o+p+1; i <= n; i++)
				cnt += a[i][3];
			ans = max(ans, cnt);
		}
		printf("%d\n", ans);
	}


	return 0;
}
