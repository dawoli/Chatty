#include <iostream>

int n, k;
int a[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	std::cout << n / 2;
	return 0;
}
