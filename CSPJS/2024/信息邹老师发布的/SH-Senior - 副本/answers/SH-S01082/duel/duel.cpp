#include<iostream>
using namespace std;
const int maxn = 1e5 + 5;
int n, ans, m;
int a[maxn];
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++) {
		scanf("%d", &x);
		m = max(m, x);
		a[x] ++;
	}
	for (int i = 1, sum = 0; i <= m; i ++) {
		if (a[i] <= sum) {
			ans += a[i];
		}
		else {
			ans += sum;
			sum = a[i];
		}
	}
	ans = n - ans;
	printf("%d", ans);
}
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
