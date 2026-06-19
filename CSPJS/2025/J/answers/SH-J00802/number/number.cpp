#include <iostream>
#include <cstring>
#include <algorithm>

std::string a;
int b[1000006], j = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin >> a;
	for (int i = 0; i < a.length(); i++)
		if ('0' <= a[i] && a[i] <= '9')
			b[j] = a[i] - '0', j++;
	std::sort(b, b + j, cmp);
	for (int i = 0; i < j; i++)
		std::cout << b[i];
	return 0;
}
