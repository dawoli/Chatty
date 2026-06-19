// 求三个数中的次大数

#include <bits/stdc++.h>
using namespace std;

int second_max(int a, int b, int c) {
	if (a >= b && a >= c) return max(b, c);
	if (b >= a && b >= c) return max(a, c);
	return max(a, b);
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << second_max(a, b, c) << '\n';
	return 0;
}
