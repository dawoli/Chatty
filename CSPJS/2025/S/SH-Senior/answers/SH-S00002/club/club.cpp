#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int a[N], b[N], c[N];
int n, ans;
void dfs(int i, int sum, int cnta, int cntb, int cntc) {
	if(i == n + 1) {
		ans = max(ans, sum);
		cout << endl;
		return;
	}
	if(cnta + 1 <= n / 2) {
		cout << 'a';
		dfs(i + 1, sum + a[i], cnta + 1, cntb, cntc);
	}
	if(cntb + 1 <= n / 2) {
		cout << 'b';
		dfs(i + 1, sum + b[i], cnta, cntb + 1, cntc);
	}
	if(cntc + 1 <= n / 2) {
		cout << 'c';
		dfs(i + 1, sum + c[i], cnta, cntb, cntc + 1);
	}
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i]; 
	}
	ans = 0;
	dfs(1, 0, 0, 0, 0); 
	cout << ans << endl;
}
int main() {
	freopen("club3.in", "r", stdin);
	freopen("club3.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
} 
