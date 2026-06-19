#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
#define ll long long
//struct Node {
//	int v[3],maxpos,id; // 记录最大的是哪个v 原编号 
//} a[maxn];
//int T,n,siz[3],usd[maxn],cnt; // siz记录每个组的人数 记录用过哪个(usd)
struct Node {
	int v[3];
} a[maxn];
int T,n;
int res,dp[maxn][3];
void dfs(int v1, int v2, int v3, int p, int sum) {
	if (v1 > n / 2 || v2 > n / 2 || v3 > n / 2) return;
	if (p == n + 1) {
		res = max(res, sum);
		return;
	}
	dfs(v1 + 1, v2, v3, p + 1, sum + a[p].v[0]);
	dfs(v1, v2 + 1, v3, p + 1, sum + a[p].v[1]);
	dfs(v1, v2, v3 + 1, p + 1, sum + a[p].v[2]);
}
bool cmp1(Node n1, Node n2) {
	return n1.v[0] > n2.v[0];
}
bool cmp0(Node n1, Node n2) {
	int tmpa[3] = {n1.v[0], n1.v[1], n1.v[2]};
	int tmpb[3] = {n2.v[0], n2.v[1], n2.v[2]};
	sort(tmpa, tmpa + 3);
	sort(tmpb, tmpb + 3);
	if (tmpa[2] == tmpb[2]) {
		if (tmpa[1] == tmpb[1]) {
			return tmpa[0] > tmpb[0];
		}
		return tmpa[1] > tmpb[1];
	}
	return tmpa[2] > tmpb[2];
//	return (n1.v[0] + n1.v[1] + n1.v[2]) > (n2.v[0] + n1.v[1] + n1.v[2]);
}
void dfs2(int v1, int v2, int v3, int p, int sum) {
	if (p == n + 1) return;
	if (sum < dp[p - 1][0] && sum < dp[p - 1][1] && sum < dp[p - 1][2]) {
		return;
	}
	if (v1 < n / 2 && dp[p][0] < sum + a[p].v[0]) {
		dp[p][0] = sum + a[p].v[0];
		dfs(v1 + 1, v2, v3, p + 1, sum + a[p].v[0]);
	}
	if (v2 < n / 2 && dp[p][1] < sum + a[p].v[1]) {
		dp[p][1] = sum + a[p].v[1];
		dfs(v1, v2 + 1, v3, p + 1, sum + a[p].v[1]);
	}
	if (v3 < n / 2 && dp[p][2] < sum + a[p].v[2]) {
		dp[p][2] = sum + a[p].v[2];
		dfs(v1, v2, v3 + 1, p + 1, sum + a[p].v[2]);
	}
//	if (p == n + 1) return;
////	if (sum < dp[p - 1][0] && sum < dp[p - 1][1] && sum < dp[p - 1][2]) {
////		return;
////	}
//	if (sum + a[p].v[0] > dp[p][0] && v1 < n / 2) {
//		dp[p][0] = sum + a[p].v[0];
//		dfs(v1 + 1, v2, v3, p + 1, sum + a[p].v[0]);
//	}
//	if (sum + a[p].v[1] > dp[p][1] && v2 < n / 2) {
//		dp[p][1] = sum + a[p].v[1];
//		dfs(v1, v2 + 1, v3, p + 1, sum + a[p].v[1]);
//	}
//	if (sum + a[p].v[2] > dp[p][2] && v3 < n / 2) {
//		dp[p][2] = sum + a[p].v[2];
//		dfs(v1, v2, v3 + 1, p + 1, sum + a[p].v[2]);
//	}
	
//	dfs(v1 + 1, v2, v3, p + 1, sum + a[p][0]);
//	dfs(v1, v2 + 1, v3, p + 1, sum + a[p][1]);
//	dfs(v1, v2, v3 + 1, p + 1, sum + a[p][2]);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d %d %d", &a[i].v[0], &a[i].v[1], &a[i].v[2]);
		res = 0;
		if (n <= 10) dfs(0, 0, 0, 1, 0);
		else if (a[1].v[1] == 0 && a[1].v[2] == 0) {
			sort(a + 1, a + 1 + n, cmp1);
			for (int i = 1; i <= n / 2; ++i) {
				res += a[i].v[0];
			}
		}
		else {
			memset(dp, 0, sizeof dp);
			sort(a + 1, a + 1 + n, cmp0);
			dfs2(0, 0, 0, 1, 0);
			res = max(res, max(dp[n][0], max(dp[n][1], dp[n][2])));
		}
		printf("%d\n", res);
	}
	return 0;
}
