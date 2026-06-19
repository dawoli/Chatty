#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, val[N], b[N], ans;
void dfs(int pos, int cnt, int l){
	int s = b[pos] ^ b[l - 1];
	if (pos == n) {
		if (s == k) ans = max(ans, cnt + 1);
		else ans = max(ans, cnt);
//		printf("%d %d %d %d\n", pos, cnt, l, ans);
		return ;
	}
	if (s == k)
		dfs(pos + 1, cnt + 1, pos + 1);
	else 
		dfs(pos + 1, cnt, pos + 1);
	dfs(pos + 1, cnt, l); 
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> val[i], b[i] = b[i - 1] ^ val[i];
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}

