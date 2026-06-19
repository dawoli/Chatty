#include <iostream>
#include <cstring>

int n;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	if (n == 1 || n == 2)
		std::cout << 0;
	if (n == 3) {
		int sum = a[1] + a[2] + a[3];
		int maxn = std::max(a[1], std::max(a[2], a[3]));
		if (sum > (maxn * 2)) std::cout << 1;
		else std::cout << 0;
	}
	if (n == 4) {
		int ans = 0;
		int sum1 = a[1] + a[2] + a[3];
		int sum2 = a[2] + a[3] + a[4];
		int sum3 = a[1] + a[2] + a[4];
		int sum4 = a[1] + a[3] + a[4];
		int sum5 = a[1] + a[2] + a[3] + a[4];
		int maxn1 = std::max(a[1], std::max(a[2], a[3]));
		int maxn2 = std::max(a[2], std::max(a[3], a[4]));
		int maxn3 = std::max(a[1], std::max(a[2], a[4]));
		int maxn4 = std::max(a[1], std::max(a[3], a[4]));
		int maxn5 = std::max(a[1], std::max(a[2], std::max(a[3], a[4])));
		if (sum1 > (maxn1 * 2)) ans++;
		if (sum2 > (maxn2 * 2)) ans++;
		if (sum3 > (maxn3 * 2)) ans++;
		if (sum4 > (maxn4 * 2)) ans++;
		if (sum5 > (maxn5 * 2)) ans++;
		std::cout << ans;
	}
	if (n == 5) {
		int ans = 0;
		int sum1 = a[1] + a[2] + a[3];
		int sum2 = a[2] + a[3] + a[4];
		int sum3 = a[3] + a[4] + a[5];
		int sum4 = a[1] + a[2] + a[4];
		int sum5 = a[1] + a[2] + a[5];
		int sum6 = a[1] + a[3] + a[4];
		int sum7 = a[1] + a[3] + a[5];
		int sum8 = a[1] + a[4] + a[5];
		int sum9 = a[2] + a[4] + a[5];
		int sum15 = a[2] + a[3] + a[5];
		int sum10 = a[1] + a[2] + a[3] + a[4];
		int sum11 = a[1] + a[2] + a[3] + a[5];
		int sum12 = a[1] + a[3] + a[4] + a[5];
		int sum13 = a[2] + a[3] + a[4] + a[5];
		int sum16 = a[1] + a[2] + a[4] + a[5];
		int sum14 = a[1] + a[2] + a[3] + a[4] + a[5];
		int maxn1 = std::max(a[1], std::max(a[2], a[3]));
		int maxn2 = std::max(a[2], std::max(a[3], a[4]));
		int maxn3 = std::max(a[3], std::max(a[4], a[5]));
		int maxn4 = std::max(a[1], std::max(a[2], a[4]));
		int maxn5 = std::max(a[1], std::max(a[2], a[5]));
		int maxn6 = std::max(a[1], std::max(a[3], a[4]));
		int maxn7 = std::max(a[1], std::max(a[3], a[5]));
		int maxn8 = std::max(a[1], std::max(a[4], a[5]));
		int maxn9 = std::max(a[2], std::max(a[4], a[5]));
		int maxn15 = std::max(a[2], std::max(a[3], a[5]));
		int maxn10 = std::max(a[1], std::max(a[2], std::max(a[3], a[4])));
		int maxn11 = std::max(a[1], std::max(a[2], std::max(a[3], a[5])));
		int maxn12 = std::max(a[1], std::max(a[3], std::max(a[4], a[5])));
		int maxn13 = std::max(a[2], std::max(a[3], std::max(a[4], a[5])));
		int maxn16 = std::max(a[1], std::max(a[2], std::max(a[4], a[5])));
		int maxn14 = std::max(a[1], std::max(a[2], std::max(a[3], std::max(a[4], a[5]))));
		if (sum1 > (maxn1 * 2)) ans++;
		if (sum2 > (maxn2 * 2)) ans++;
		if (sum3 > (maxn3 * 2)) ans++;
		if (sum4 > (maxn4 * 2)) ans++;
		if (sum5 > (maxn5 * 2)) ans++;
		if (sum6 > (maxn6 * 2)) ans++;
		if (sum7 > (maxn7 * 2)) ans++;
		if (sum8 > (maxn8 * 2)) ans++;
		if (sum9 > (maxn9 * 2)) ans++;
		if (sum10 > (maxn10 * 2)) ans++;
		if (sum11 > (maxn11 * 2)) ans++;
		if (sum12 > (maxn12 * 2)) ans++;
		if (sum13 > (maxn13 * 2)) ans++;
		if (sum14 > (maxn14 * 2)) ans++;
		if (sum15 > (maxn15 * 2)) ans++;
		if (sum16 > (maxn16 * 2)) ans++;
		std::cout << ans;
	}
	return 0;
}
