#include <bits/stdc++.h>
using namespace std;
int n, r[100005], cnt[100005], ans, sum; 
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout); 
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> r[i];
		++cnt[r[i]];
	}
	sort(r + 1, r + n + 1);
	sum = cnt[r[1]];
	for(int i = 2; i <= n; ++i) {
		if(r[i] != r[i - 1]) {
			ans += min(sum, cnt[r[i]]);
			sum -= min(sum, cnt[r[i]]);
			sum += cnt[r[i]]; 
		}
	}
	cout << n - ans << endl;
	return 0;
}
// ORZ COMPOSITE_FUNCTION
// ORZ JXY2011
// ORZ LITTLEACBG
// ORZ LIAOYANXU
// ORZ TIANTIAN2021

// everything i want to say is in T4 code
