#include <bits/stdc++.h>  //Ô¤¹À100
using namespace std;

const int N = 1e5 + 10;
int n, a[N], l, r, ans;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	l = 1;
	ans = n;
	for (r = 2; r <= n; ++ r) {
		if (a[r] > a[l]) {
			l ++;
			ans --;
		}
	}

	cout << ans << endl;
	return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
