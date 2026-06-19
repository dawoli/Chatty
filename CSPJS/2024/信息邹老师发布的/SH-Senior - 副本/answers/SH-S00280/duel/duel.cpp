#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n, r[N], nC, num[N], ans;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", r + i);
	sort(r + 1, r + n + 1);
	int cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (r[i] == r[i - 1]) cnt++;
		else num[++nC] = cnt, cnt = 1;
	}
	num[++nC] = cnt;
	for (int i = 1; i <= nC; i++)
		ans = max(0, ans - num[i]) + num[i];
	printf("%d\n", ans);
	return 0;
}
