#include <bits/stdc++.h>

const int N = 1e5 + 2;

int n, a[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
//	freopen("duel4.in", "r", stdin);
//	freopen("ans.txt", "w", stdout);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + 1 + n);
	int j = 1;
	for (int i = 1; i <= n; i++) {
		if (a[j] < a[i]) {
			j++;
		}
	}
	std::cout << n - j + 1;
	return 0;
}
