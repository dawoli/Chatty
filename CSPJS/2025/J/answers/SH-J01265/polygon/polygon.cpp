//01-11-25 10:18
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL N = 5005, MOD = 998244353;

LL n, a[N], ans;
void dfs(LL k, LL sum, LL mx, LL cnt){
	if(k > n){
		if(sum > mx * 2 && cnt >= 3)
			ans = (ans + 1) % MOD;
		return;
	}
	
	dfs(k + 1, sum + a[k], max(mx, a[k]), cnt + 1);
	dfs(k + 1, sum, mx, cnt);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(LL i = 1; i <= n; ++ i)
		cin >> a[i];
	
	bool flag = true;
	for(LL i = 1; i <= n; ++ i)
		if(a[i] != 1){
			flag = false;
			break;
		}
	
	if(flag){
		cout << n * (n - 1) / 2 * (n - 2) / 3 % MOD;
		return 0;
	}
	
	sort(a + 1, a + n + 1);
	
//	for(LL i = 1; i <= n; ++ i){
		dfs(1, 0, 0, 0);
//	}
	cout << ans;
	return 0;
}
