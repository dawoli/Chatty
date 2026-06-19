#include <bits/stdc++.h>
using namespace std;
int n, val[100005], cnt;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> val[i];
	sort(val + 1, val + n + 1);
	for(int l = 1, r = 1; l <= n; l++) {
		while((val[r] <= val[l]) && r < n) r++;
		if(val[r] > val[l]) {
			cnt++; r++;
			if(r > n) break;
		}
		else break;
	}
	cout << n - cnt;
	return 0;
}
