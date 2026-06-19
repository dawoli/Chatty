# include <iostream>
# include <cstdio>
# include <algorithm>

const int NR = 1e5 + 10;
int a[NR], N, ans;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x = 0;
		scanf("%d", &x);
		a[x]++;
		ans = std::max(ans, a[x]);
	}
	printf("%d\n", ans);
	return 0;
}
