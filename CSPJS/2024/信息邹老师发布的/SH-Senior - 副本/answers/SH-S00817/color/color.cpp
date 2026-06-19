#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N], col[N], ans = -1e9;
void dfs(int x, int n) {
	if(x > n) {
		int sum = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i - 1; j >= 1; j--) {
				if(col[j] == col[i]) {
					if(a[j] == a[i]) sum += a[i];
					else break;
				}
			}
		if(ans < sum) {
			//for(int i = 1; i <= n; i++) cout << col[i] << " ";
			//cout << " ";
			//cout << sum << "\n";
			ans = sum;
		}
		return;
	}
	col[x] = 1; dfs(x + 1, n);
	col[x] = 2; dfs(x + 1, n);
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		ans = -1e9;
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		//for(int i = 1; i <= n; i++) cout << a[i] << " ";
		//cout << "\n";
		dfs(1, n);
		cout << ans << "\n";
	}
	return 0;
}
