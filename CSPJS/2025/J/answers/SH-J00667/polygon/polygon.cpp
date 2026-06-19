#include <bits/stdc++.h>
using namespace std;
long long n, cnt, ans, a[5005], b[5005], vis[5005];
void dfs(int x){
	if(x > n) return;
	if(cnt > b[x] && vis[x]) ans ++;
	vis[x + 1] = 1;
	cnt += a[x + 1];
	dfs(x + 1);
	vis[x + 1] = 0;
	cnt -= a[x + 1];
	dfs(x + 1);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	b[0] = b[1] = b[2] = 1e9;
	for(int i = 3; i <= n; i ++) b[i] = a[i] * 2;
	dfs(0);
	cout << ans % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
