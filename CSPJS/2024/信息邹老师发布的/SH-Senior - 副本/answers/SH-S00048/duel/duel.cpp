#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
const int N = 1e5 + 9;
int n, ans, a[N];
std::priority_queue<int, std::vector<int>, std::greater<int>> pque;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	ans = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	std::sort(a + 1, a + n + 1);
	pque.emplace(a[1]);
	for (int i = 2; i <= n; i++) {
		if (pque.size() and a[i] <= pque.top()) {
			pque.emplace(a[i]);
		} else {
			pque.pop(); ans--;
			pque.emplace(a[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
