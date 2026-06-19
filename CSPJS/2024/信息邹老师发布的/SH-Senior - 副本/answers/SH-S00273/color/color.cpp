#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110, MAXA = 110;
int aList[MAXN], n;
int dp[MAXN][MAXA][MAXA];
int dfs(int nowA, int lastR, int lastB) {
	if (nowA > n) return 0;
	if (dp[nowA][lastR][lastB] != -1) {
		return dp[nowA][lastR][lastB];
	}
	int ret = 0;
	if (aList[nowA] == lastR) {
		ret = max(ret, dfs(nowA + 1, aList[nowA], lastB) + lastR);
	}
	else {
		ret = max(ret, dfs(nowA + 1, aList[nowA], lastB));
	}
	if (aList[nowA] == lastB) {
		ret = max(ret, dfs(nowA + 1, lastR, aList[nowA]) + lastB);
	}
	else {
		ret = max(ret, dfs(nowA + 1, lastR, aList[nowA]));
	}
	dp[nowA][lastR][lastB] = ret;
	return ret;
}
int main () {
	int T;
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 0; t < T; t ++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &aList[i]);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", dfs(1, 0, 0)); 
	}
	return 0;
}
