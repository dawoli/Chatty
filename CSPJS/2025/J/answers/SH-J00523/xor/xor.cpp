#include<bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, k, d, maxx = -1, ans = 0;
int a[maxn], sum[maxn], p[maxn];
bool vis[maxn];
void dfs(int l, int r) {
	if (r == d) {
		maxx = max(maxx, ans);
		return;
	}
	//cout << d << endl;
	//cout << l << " " << r << " " << ans << endl;
	for (int i = r + 1; i <= d; i++) {
		if (p[i] && !vis[i]) {
			ans++;
			vis[i] = true;
			//cout << i << " " << j << " " << ans << endl;
			dfs(i, p[i]);
			ans--;
			//vis[i] = false;
		}
	}
	return; 
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(sum, 0, sizeof(sum));
	memset(p, 0, sizeof(p));
	memset(vis, false, sizeof(vis));
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	/*for (int i = 1; i <= n; i++) {
		cout << sum[i] << " ";
	}
	cout <<endl;
	*/
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int x = sum[j] ^ sum[i - 1];
			if (x == k && !vis[i]) {
				//cout << i << " " << j << " " << x << endl;
				p[i] = j;
				vis[i] = true;
				d = j;
			}
		} 
	} 
	//cout << d <<endl;
	/*for (int i = 1; i <= n; i++) {
		cout << p[i] <<" ";
	}*/
	memset(vis, false, sizeof(vis));
	dfs(0, 0);
	cout << maxx << endl;
	return 0;
}
