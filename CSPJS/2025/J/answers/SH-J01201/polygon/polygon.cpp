#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
int a[5005];
int n, ans;

void dfs(int idx, int sum, int maxn, int cnt){
	if(sum > 2 * maxn && cnt >= 3){
		ans++;
		ans %= MOD;
		return;
	}
	if(idx == n + 1)
		return;
	
	dfs(idx + 1, sum, maxn, cnt);
	
	dfs(idx + 1, sum + a[idx], max(maxn, a[idx]), cnt + 1);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n - 1; i++)
		dfs(i, 0, -1, 0);
	cout << ans % MOD << endl;
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
