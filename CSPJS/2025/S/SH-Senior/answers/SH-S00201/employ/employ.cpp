#include <bits/stdc++.h>
using namespace std;
int n,m,len,x;
long long res;
string str1;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	res = 1;
	cin >> str1;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (x == 0) len++;
	}
	for (int i = 1; i <= len; ++i) {
		res = res * i;
		res %= 998244353;
	}
	long long res2 = 1;
	for (int i = 1; i <= n - len; ++i) {
		res2 = res2 * i;
		res2 %= 998244353;
	}
	printf("%lld", (res * res2) % 998244353);
	return 0;
}
